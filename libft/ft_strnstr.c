/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:24:38 by vheidy            #+#    #+#             */
/*   Updated: 2019/09/17 19:50:49 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t l;

	l = ft_strlen((char*)needle);
	if (!l)
		return ((char*)haystack);
	if (l >= len || l <= ft_strlen((char*)haystack))
	{
		while (*haystack && len-- >= l)
			if (!ft_memcmp(haystack++, needle, l))
				return ((char*)(haystack - 1));
	}
	return (NULL);
}
