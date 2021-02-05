/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:32:27 by vheidy            #+#    #+#             */
/*   Updated: 2019/09/11 21:07:35 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		j;
	int		i;
	int		len;
	char	*tmp;

	if (!(s))
		return (0);
	i = 0;
	j = 0;
	len = ft_strlen((char*)s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == len)
		return (ft_strnew(0));
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	tmp = ft_strnew(len - i);
	if (NULL == tmp)
		return (0);
	while (i < len)
		tmp[j++] = s[i++];
	return (tmp);
}
