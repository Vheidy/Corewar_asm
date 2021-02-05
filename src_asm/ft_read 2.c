/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:54:04 by polina            #+#    #+#             */
/*   Updated: 2021/01/14 21:02:46 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_find_space(char c)
{
	if (c && (c == ' ' || c == '\f' || c == '\v' \
			|| c == '\t' || c == '\r'))
		return (1);
	return (0);
}

/*
 ** Проверка на альтернативный комментарий
*/
void	ft_check_alt_comment(char *start)
{
	while (*start && ft_find_space(*start))
		start++;
	if (*start && *start != ALT_COMMENT_CHAR)
		error();
}

/*
 ** Считывание имени или комментария
*/
void	ft_parse_name_or_comment(t_asm *st, char **str, char **buf)
{
	char	*quote_one;
	char	*quote_two;
	char	*end;
	int		red;
	char	*tmp;
	char	*next_line;

	end = *buf;
	while (*end)
		end++;
	if (!(quote_one = ft_strchr(*buf, '"')))
		error();
	if ((quote_two = ft_strchr(++quote_one, '"')))
		*str = ft_strsub(quote_one, 0, quote_two - quote_one);
	else
	{
		tmp = ft_strsub(quote_one, 0, end - quote_one);
		next_line = ft_strdup("\n");
		*str = ft_strjoin_free_all(&tmp, &next_line);
		free(*buf);
		if ((red = get_next_line(st->fd_orig, buf)) > 0)
		{
			while (red > 0 && !(quote_two = ft_strchr(*buf, '"')))
			{
				next_line = ft_strdup("\n");
				*str = ft_strjoin_free_all(str, buf);
				*str = ft_strjoin_free_all(str, &next_line);
				red = get_next_line(st->fd_orig, buf);
			}
			tmp = ft_strsub(*buf, 0, quote_two - *buf);
			*str = ft_strjoin_free_all(str, &tmp);
		}
	}
	ft_check_alt_comment(++quote_two);
	free(*buf);
}

/*
 ** Продолжение ft_parse_instruction
 ** считает имя и закинет на проверку такого в функцию ft_find_command
*/

void	ft_read_command(char *command, t_asm *st, int fl)
{
	char	*end;
	char	*tmp;
	// char	*start_args;

	end = command;
	while (*end && (!ft_find_space(*end) && *end != DIRECT_CHAR && \
		!ft_isdigit(*end) && *end != LABEL_CHAR))
		end++;
	// start_args = end;
	// while (*start_args && ft_find_space(*start_args))
	// 	start_args++;
	// printf("%s\n", ft_strsub(command, 0, end - command));
	tmp = ft_strsub(command, 0, end - command);
	if (fl)
		st->count_bytes += ft_find_command(tmp, end);
	else
	{
		ft_select_command(st, tmp, end);
		st->curr_pos += ft_find_command(tmp, end);
	}
	free(tmp);
}

/*
 ** Считывание инструкции
 ** Проверка на метку, если есть метка добавит ее в лист
 ** Продолжение считывание инструкции в read_command
*/

void	ft_parse_instruction(t_asm *st, char **buf)
{
	char	*colon;
	int		i;

	i = 0;
	if ((colon = ft_strchr(*buf, LABEL_CHAR)) && ft_strchr(LABEL_CHARS, *(colon - 1)))
	{
		ft_add_label(ft_create_name_label(colon, buf), st);
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

/*
 ** Первое считывание
 ** Делается для проверки наличия имени, коммента и корректности всех команд
 ** а таже для заполнения листов с метками
*/
void	ft_first_read(t_asm *st)
{
	int		red;
	char	*buf;

	while ((red = get_next_line(st->fd_orig, &buf)))
	{
		if (ft_strlen(buf) != 0 && buf[0] != COMMENT_CHAR)
		{
			// printf("%s\n", buf);
			if (buf[0] == '.')
			{
				if (!ft_strcmp(ft_strsub(buf, 0, 5), NAME_CMD_STRING))
					ft_parse_name_or_comment(st, &(st->name), &buf);
				else if (!ft_strcmp(ft_strsub(buf, 0, 8), COMMENT_CMD_STRING))
					ft_parse_name_or_comment(st, &(st->comment), &buf);
			}
			else if (ft_strlen(buf) != 0)
				ft_parse_instruction(st, &buf);
		}
	}
}

// void	ft_read_second()

/*
 ** Первое считывание и затем второе
 ** Первое необходимо для анализа синтаксиса и заполнения листа с метками
 ** Второе уже для перевода в байт код
*/

void	ft_read(t_asm *st, char *name)
{
	ft_first_read(st);
	if (!st->name || !st->comment)
		error();
	// printf("Name: %s\nComment: %s\n", st->name, st->comment);
	// printf("ok\n");
	if ((close(st->fd_orig)) == -1 || \
	(st->fd_orig = open(name, O_RDONLY)) == -1)
		error();
	st->fd_res = 1;
	// ft_second_read(st);
}