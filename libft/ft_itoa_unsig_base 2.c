/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsig_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:02:29 by rtacos            #+#    #+#             */
/*   Updated: 2020/12/02 20:22:34 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		print_nbr(int value, int reg)
{
	char *str;
	char c;

	if (reg)
		str = ft_strdup("0123456789ABCDEF");
	else
		str = ft_strdup("0123456789abcdef");
	c = str[value];
	ft_strdel(&str);
	return (c);
}

char			*ft_itoa_unsig_base(t_ull_int value, int base, int num, int reg)
{
	char		*str;
	int			count;

	count = ft_base_intlen(value, base) + (num > 0 ? num : 0);
	str = malloc(sizeof(char) * (count + 1));
	str[count] = '\0';
	while (value >= (t_ull_int)base)
	{
		str[--count] = print_nbr(value % base, reg);
		value /= base;
	}
	str[--count] = print_nbr(value % base, reg);
	while (num-- > 0)
		str[--count] = print_nbr(0, reg);
	return (str);
}
