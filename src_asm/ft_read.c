/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:54:04 by polina            #+#    #+#             */
/*   Updated: 2021/02/05 14:35:03 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_read_command(char *command, t_asm *st, int fl)
{
	char	*end;
	char	*tmp;

	end = command;
	while (*end && (!ft_find_space(*end) && *end != DIRECT_CHAR && \
		!ft_isdigit(*end) && *end != LABEL_CHAR && *end != '-'))
		end++;
	tmp = ft_strsub(command, 0, end - command);
	if (fl)
		st->count_bytes += ft_find_command(tmp, end, st);
	else
	{
		ft_select_command(st, tmp, end);
		st->curr_pos += ft_find_command(tmp, end, st);
	}
	free(tmp);
}

void	ft_parse_instruction(t_asm *st, char **buf)
{
	char	*colon;
	int		i;

	i = 0;
	if ((colon = ft_strchr(*buf, LABEL_CHAR)) && ft_strchr(LABEL_CHARS, *(colon - 1)))
	{
		ft_add_label(ft_create_name_label(colon, buf, st), st);
		colon++;
		while (colon[i] && ft_find_space(colon[i]))
			i++;
		if (colon[i])
			ft_read_command(&colon[i], st, 1);
	}
	else
	{
		while ((*buf)[i] && ft_find_space((*buf)[i]))
				i++;
		if ((*buf)[i])
			ft_read_command(&(*buf)[i], st, 1);
	}
	free(*buf);
}

void	ft_check_condition(char **buf, t_asm *st)
{
	char	*tmp;

	if (!ft_strcmp((tmp = ft_strsub(*buf, 0, 5)), NAME_CMD_STRING))
	{
		free(tmp);
		ft_parse_name_or_comment(st, st->name, buf);
	}
	else if (!ft_strcmp((tmp = ft_strsub(*buf, 0, 8)), COMMENT_CMD_STRING))
	{
		free(tmp);
		ft_parse_name_or_comment(st, st->comment, buf);
	}
	st->header_end = st->string_num;
}

void	ft_first_read(t_asm *st)
{
	int		red;
	char	*buf;

	st->name = (char *)ft_memalloc(PROG_NAME_LENGTH);
	st->comment = (char *)ft_memalloc(COMMENT_LENGTH);
	while ((red = get_next_line(st->fd_orig, &buf)) > 0)
	{
		st->string_num++;
		if (ft_strlen(buf) && !ft_check_alt_comment(buf))
		{
			if (buf[0] == '.')
				ft_check_condition(&buf, st);
			else
				ft_parse_instruction(st, &buf);
		}
	}
}

void	ft_read(t_asm *st, char *name, char *old_name)
{
	ft_check_end_line(st);
	ft_first_read(st);
	if (!*st->name || !*st->comment)
		error("Missing champion name or comment", 0);
	st->string_num = 0;
	if ((close(st->fd_orig)) == -1 || \
	(st->fd_orig = open(old_name, O_RDONLY)) == -1)
		error("Failed to open file", 0);
	if (!(st->exec_code = (unsigned char*)ft_memalloc(st->count_bytes)))
		error("Failed to allocate memory", 0);
	if (!st->count_bytes)
		error("Champion don't have executable code", 0);
	ft_second_read(st);
	write(st->fd_res, st->exec_code, st->count_bytes);
	write(1, "Writing output program to ", 26);
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
	if (close(st->fd_orig) == -1 || close(st->fd_res) == -1)
		error("Failed to close file", 0);
}
