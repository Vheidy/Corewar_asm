/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:42:31 by polina            #+#    #+#             */
/*   Updated: 2021/02/05 14:57:19 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_check_name(char *name)
{
	char	*point;
	char	*tmp_name;
	char	*new_name;

	if (!(point = ft_strchr(name, '.')))
		error("Wrong file extension", 0);
	tmp_name = ft_strsub(name, 0, point - name);
	point++;
	if (ft_strcmp(point, "s"))
		error("Wrong file extension", 0);
	new_name = ft_strjoin(tmp_name, ".cor");
	free(tmp_name);
	return (new_name);
}

char	*ft_join_with_new_line(char **str)
{
	char	*next_line;
	char	*res;

	next_line = ft_strdup("\n");
	res = ft_strjoin_free_all(str, &next_line);
	return (res);
}

void	ft_read_to_secod_quotes(t_asm *st, char **str)
{
	int		red;
	char	*quote_two;
	char	*tmp;
	char	*buf;

	while ((red = get_next_line(st->fd_orig, &buf)) > 0 && \
	!(quote_two = ft_strchr(buf, '"')))
	{
		st->string_num++;
		*str = ft_strjoin_free_all(str, &buf);
		*str = ft_join_with_new_line(str);
	}
	st->string_num++;
	if (!quote_two)
		error("Missing second quotes", 0);
	tmp = ft_strsub(buf, 0, quote_two - buf);
	*str = ft_strjoin_free_all(str, &tmp);
	free(buf);
}

void	ft_parse_name_or_comment(t_asm *st, char *res, char **buf)
{
	char	*quote_one;
	char	*quote_two;
	char	*end;
	char	*str;

	end = *buf;
	while (*end)
		end++;
	// printf("%s\n", *buf);
	if (!(quote_one = ft_strchr(*buf, '"')))
		error("Missing quotes ", st->string_num);
	if ((quote_two = ft_strchr(++quote_one, '"')))
		str = ft_strsub(quote_one, 0, quote_two - quote_one);
	else
	{
		str = ft_strsub(quote_one, 0, end - quote_one);
		str = ft_join_with_new_line(&str);
		ft_read_to_secod_quotes(st, &str);
		// printf("%s\n", str);
	}
	ft_strcpy(res, str);
	if (quote_two && !ft_check_alt_comment(++quote_two))
		error("You have something extra at the end of the line ", st->string_num);
	// printf("ok\n");
	free(str);
	free(*buf);
}
