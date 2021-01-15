/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:38:21 by vheidy            #+#    #+#             */
/*   Updated: 2019/09/11 20:33:07 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(sub = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
		*(sub + i++) = *(s + start++);
	sub[i] = '\0';
	return (sub);
}
