/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:26:55 by rtacos            #+#    #+#             */
/*   Updated: 2020/07/07 20:55:31 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_skip_size(int size)
{
	int		i;

	i = 0;
	if (size == HH || size == LL)
		++i;
	return (i);
}

int		ft_zero_skip(const char *format)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (format[i++] == '0')
		count++;
	return (count);
}
