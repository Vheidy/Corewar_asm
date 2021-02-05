/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:38:31 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/11 14:47:29 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		space(char c)
{
	if (c == ' ' || c == '\n' || c == '\f' || c == '\v'
			|| c == '\t' || c == '\r')
		return (1);
	return (0);
}

long long int	ft_atoi(const char *s)
{
	int				fl;
	long long int	at;
	long long int	r;
	int				i;

	fl = 1;
	at = 0;
	i = 0;
	while (space(s[i]) == 1)
		i++;
	if (s[i] == '-')
		fl = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (ft_isdigit(s[i]) == 1)
	{
		r = at;
		at = at * 10 + (s[i] - '0');
		if (r != (at / 10) && fl == 1)
			return (-1);
		if (r != (at / 10) && fl == -1)
			return (0);
		i++;
	}
	return (at * fl);
}
