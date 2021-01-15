/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 20:00:20 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/11 20:33:11 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int f1, int f2)
{
	char	*tmp;

	if (!s1)
	{
		s1 = ft_strnew(0);
		f1 = 1;
	}
	if (!s2)
	{
		s2 = ft_strnew(0);
		f2 = 1;
	}
	tmp = ft_strjoin(s1, s2);
	if (f1 == 1)
		free(s1);
	if (f2 == 1)
		free(s2);
	return (tmp);
}
