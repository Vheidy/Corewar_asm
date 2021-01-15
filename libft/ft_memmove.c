/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:51:37 by vheidy            #+#    #+#             */
/*   Updated: 2019/09/11 19:12:59 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = 0;
	if (src == dst)
		return (dst);
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	if (dst > src)
	{
		while (len != 0)
		{
			len--;
			d[len] = s[len];
		}
	}
	else
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	return (dst);
}
