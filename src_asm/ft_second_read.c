/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:59:46 by polina            #+#    #+#             */
/*   Updated: 2021/02/05 14:37:11 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_check_end_line(t_asm *st)
{
	char	buf[1];

	if (lseek(st->fd_orig, -1, SEEK_END) == -1L)
		error("Failed to seek", 0);
	if (!read(st->fd_orig, buf, 1))
		error("Failed to read file", 0);
	if (buf[0] != '\n')
		error("File must end with an empty line", 0);
	if (lseek(st->fd_orig, 0, SEEK_SET) == -1L)
		error("Failed to seek", 0);
}

void	ft_select_command(t_asm *st, char *name, char *args)
{
	int				i;

	i = -1;
	while (++i < 16)
		if (!ft_strcmp(st->op_tab[i].name, name))
			ft_print_command(st, i, args);
}

void	ft_support_parse(int i, char *buf, t_asm *st)
{
	char	*colon;

	if ((colon = ft_strchr(buf, LABEL_CHAR)) && \
	ft_strchr(LABEL_CHARS, *(colon - 1)))
	{
		colon++;
		while (colon[i] && ft_find_space(colon[i]))
			i++;
		if (colon[i])
			ft_read_command(&colon[i], st, 0);
	}
	else
	{
		while (buf[i] && ft_find_space(buf[i]))
				i++;
		if (buf[i])
			ft_read_command(&buf[i], st, 0);
	}
}

void	ft_parse_without_less(t_asm *st)
{
	int		red;
	char	*buf;
	int		i;

	while ((red = get_next_line(st->fd_orig, &buf)))
	{
		st->string_num++;
		if (st->string_num > st->header_end && ft_strlen(buf) != 0 && \
		!ft_check_alt_comment(buf) && buf[0] != '.')
		{
			i = 0;
			ft_support_parse(i, buf, st);
		}
		free(buf);
	}
}

void	ft_second_read(t_asm *st)
{
	int		magic;
	int				test;
	unsigned char	*pointer;

	test = 1;
	pointer = (unsigned char*)&test;
	if (*pointer)
		st->little_endian = 1;
	else
		st->little_endian = 0;
	magic = COREWAR_EXEC_MAGIC;
	if (st->little_endian)
		magic = ft_convert_to_big_endian(magic);
	write(st->fd_res, &magic, 4);
	write(st->fd_res, st->name, PROG_NAME_LENGTH);
	magic = 0;
	write(st->fd_res, &magic, 4);
	if (st->little_endian)
		magic = ft_convert_to_big_endian(st->count_bytes);
	write(st->fd_res, &magic, 4);
	write(st->fd_res, (st->comment), COMMENT_LENGTH);
	magic = 0;
	write(st->fd_res, &magic, 4);
	ft_parse_without_less(st);
}
