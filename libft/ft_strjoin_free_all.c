/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:30:17 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/13 17:51:49 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_all(char **s1, char **s2)
{
	char	*tmp;

	if (!*s1)
		*s1 = ft_strnew(0);
	if (!*s2)
		*s2 = ft_strnew(0);
	tmp = ft_strjoin(*s1, *s2);
	free(*s1);
	free(*s2);
	return (tmp);
}
