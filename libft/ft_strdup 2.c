/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:56:56 by vheidy            #+#    #+#             */
/*   Updated: 2020/12/02 16:58:10 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	str = NULL;
	if (s1)
	{
		while (s1[len] != '\0')
			len++;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (0);
		while (*s1)
		{
			str[i] = *s1;
			i++;
			s1++;
		}
		str[i] = '\0';
	}
	return (str);
}
