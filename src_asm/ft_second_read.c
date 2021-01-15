/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:59:46 by polina            #+#    #+#             */
/*   Updated: 2021/01/14 19:14:25 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_write_hex(int elem, int fd)
{
	char res;

	if (elem >= 16)
		ft_write_hex(elem / 16, fd);
	res = elem % 16 + (elem % 16 < 10 ? '0' : 'a' - 10);
	write(fd, &res, 1);
}

void	ft_hex_to_char(char c, char *tmp)
{
	char	res;
	int		elem;

	elem = c;
	res = elem / 16;
	if (elem >= 16)
		ft_hex_to_char(res, tmp - 1);
	*tmp = elem % 16 + (elem % 16 < 10 ? '0' : 'a' - 10);
}

void	ft_create_name(t_asm *st)
{
	char	name[PROG_NAME_LENGTH * 2 + 1];
	char	*tmp;
	int		i;
	int		len;

	i = -1;
	ft_bzero(name, PROG_NAME_LENGTH * 2);
	name[PROG_NAME_LENGTH * 2] = '\0';
	tmp = name;
	while (st->name[++i] && i < PROG_NAME_LENGTH * 2)
	{
		ft_hex_to_char(st->name[i], tmp + 1);
		tmp = tmp + 2;
	}
	len = PROG_NAME_LENGTH * 2 - ft_strlen(name);
	while (--len)
	{
		*tmp = '0';
		tmp++;
	}
	write(st->fd_res, &name, PROG_NAME_LENGTH * 2);
}

void	ft_create_comment(t_asm *st)
{
	char	comment[COMMENT_LENGTH * 2 + 1];
	char	*tmp;
	int		i;
	int		len;

	i = -1;
	ft_bzero(comment, COMMENT_LENGTH * 2);
	comment[COMMENT_LENGTH * 2] = '\0';
	tmp = comment;
	while (st->comment[++i] && i < COMMENT_LENGTH * 2)
	{
		ft_hex_to_char(st->comment[i], tmp + 1);
		tmp = tmp + 2;
	}
	len = COMMENT_LENGTH * 2 - ft_strlen(comment);
	while (--len)
	{
		*tmp = '0';
		tmp++;
	}
	write(st->fd_res, &comment, COMMENT_LENGTH * 2);
}

void	ft_print_null(t_asm *st, int size)
{
	int		i;

	i = 0;
	while (i++ < size)
		write(st->fd_res, "0", 1);
	
}

int		ft_len_hex(int elem)
{
	int		len;

	len = 1;
	while (elem / 16)
	{
		len++;
		elem /= 16;
	}
	return (len);
}

void	ft_parse_without_less(t_asm *st)
{
	int		red;
	char	*buf;
	char	*colon;
	int		i;

	i = 0;
	while ((red = get_next_line(st->fd_orig, &buf)))
	{
		if (ft_strlen(buf) != 0 && buf[0] != COMMENT_CHAR && 
		!buf[0] == '.' && ft_strlen(buf) != 0)
		{
			if ((colon = ft_strchr(*buf, LABEL_CHAR)) && ft_strchr(LABEL_CHARS, *(colon - 1)))
			{
				colon++;
				while (colon[i] && ft_find_space(colon[i]))
					i++;
				if (colon[i])
					ft_read_command(&colon[i], st, 0);
			}
			else
			{
				while ((*buf)[i] && ft_find_space((*buf)[i]))
						i++;
				if ((*buf)[i])
					ft_read_command(&(*buf)[i], st, 0);
			}
		}
		free(buf);
	}
}

void	ft_second_read(t_asm *st)
{
	ft_print_null(st, (8 - ft_int_len(COREWAR_EXEC_MAGIC) - 2));
	ft_write_hex(COREWAR_EXEC_MAGIC, st->fd_res);
	ft_create_name(st);
	ft_print_null(st, 8);
	// printf("Count bytes %d\n", st->count_bytes);
	ft_print_null(st, 8 - ft_len_hex(st->count_bytes));
	ft_write_hex(st->count_bytes, st->fd_res);
	ft_create_comment(st);
	ft_print_null(st, 8);
	ft_parse_without_less(st);
}