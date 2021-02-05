/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:53:45 by vheidy            #+#    #+#             */
/*   Updated: 2019/09/17 19:48:31 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tm1;
	unsigned char	*tm2;
	size_t			i;

	i = 0;
	tm1 = (unsigned char*)s1;
	tm2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (tm1[i] != tm2[i])
			return (tm1[i] - tm2[i]);
		i++;
	}
	return (tm1[i - 1] - tm2[i - 1]);
}
