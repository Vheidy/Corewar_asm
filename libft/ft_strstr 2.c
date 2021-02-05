/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:12:16 by vheidy            #+#    #+#             */
/*   Updated: 2019/09/11 14:35:38 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	if (!*needle || needle == haystack)
		return ((char*)haystack);
	i = 0;
	while (*haystack)
	{
		while (haystack[i] == needle[i] && needle[i])
			i++;
		if (!needle[i])
			return ((char*)haystack);
		i = 0;
		haystack++;
	}
	return (NULL);
}
