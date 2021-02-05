/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:39:02 by polina            #+#    #+#             */
/*   Updated: 2021/02/05 14:36:49 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_convert_to_big_endian(int elem)
{
	int	res;

	res = ((elem >> 24) & 0xff)
	| ((elem >> 16) & 0xff) << 8
	| ((elem >> 8) & 0xff) << 16
	| (elem & 0xff) << 24;
	return (res);
}

int		ft_find_space(char c)
{
	if (c && (c == ' ' || c == '\f' || c == '\v' \
			|| c == '\t' || c == '\r'))
		return (1);
	return (0);
}

int		ft_check_alt_comment(char *start)
{
	while (*start && ft_find_space(*start))
		start++;
	if (*start && *start != ALT_COMMENT_CHAR && *start != COMMENT_CHAR)
		return (0);
	return (1);
}

void	error(char *str, int num_string)
{
	char	*num;

	write(2, "ERROR: ", 7);
	write(2, str, ft_strlen(str));
	if (num_string)
	{
		num = ft_itoa(num_string, 0);
		write(2, ": Line ", 7);
		write(2, num, ft_strlen(num));
	}
	write(2, "\n", 1);
	exit(0);
}

char	*ft_del_space(char *str, t_asm *st)
{
	char	*start;
	char	*end;

	start = str;
	while (ft_find_space(*start))
		start++;
	end = start;
	if (!*start)
		error("No argument ", st->string_num);
	while (*end && !ft_find_space(*end))
		end++;
	if (!ft_check_alt_comment(end))
		error("You have something extra at the end of the line ", st->string_num);
	return (ft_strsub(start, 0, end - start));
}
