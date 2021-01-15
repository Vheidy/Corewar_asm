/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_n_line_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:55:28 by rtacos            #+#    #+#             */
/*   Updated: 2020/07/06 17:56:48 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put_n_line_char(char const *s, int n, int fd)
{
	int		i;

	i = 0;
	if (s && n > 0)
		while (*s && n--)
		{
			i++;
			ft_putchar_fd(*s++, fd);
		}
	return (i);
}
