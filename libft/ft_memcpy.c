/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:26:39 by vheidy            #+#    #+#             */
/*   Updated: 2019/09/18 16:41:58 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = 0;
	if (dst == src)
		return (dst);
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
