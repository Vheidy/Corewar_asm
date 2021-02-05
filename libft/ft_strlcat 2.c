/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:38:23 by vheidy            #+#    #+#             */
/*   Updated: 2019/09/11 19:15:29 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*s1;
	char	*s2;

	i = 0;
	j = 0;
	s1 = (char*)dst;
	s2 = (char*)src;
	if (size == 0)
		return (ft_strlen(s2));
	while (s1[i] != '\0' && i < size)
		i++;
	j = i;
	while (s2[i - j] != '\0' && i < size - 1)
	{
		s1[i] = s2[i - j];
		i++;
	}
	if (i < size)
		s1[i] = '\0';
	return (j + ft_strlen(s2));
}
