/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:01:42 by vheidy            #+#    #+#             */
/*   Updated: 2019/09/11 19:17:01 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		len;

	tmp = (char*)s;
	len = ft_strlen(tmp);
	while (len >= 0)
	{
		if (tmp[len] == c)
			return (&tmp[len]);
		len--;
	}
	return (NULL);
}
