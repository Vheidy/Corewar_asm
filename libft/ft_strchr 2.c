/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:26:13 by vheidy            #+#    #+#             */
/*   Updated: 2020/12/17 21:19:15 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	if (*s)
	{
		temp = (char*)s;
		while (temp[i] != c && temp[i] != '\0')
			i++;
		if (temp[i] == '\0' && c != '\0')
			return (NULL);
		return (&temp[i]);
	}
	return (NULL);
}
