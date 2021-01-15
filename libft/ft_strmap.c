/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:01:24 by vheidy            #+#    #+#             */
/*   Updated: 2019/09/11 19:14:35 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;
	size_t	len;

	if (!(s) || !(f))
		return (0);
	len = ft_strlen((char*)s);
	tmp = ft_strnew(len);
	if (tmp == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		tmp[i] = (*f)(s[i]);
		i++;
	}
	return (tmp);
}
