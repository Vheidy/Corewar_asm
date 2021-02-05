/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_two_dim_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:32:42 by polina            #+#    #+#             */
/*   Updated: 2021/01/26 16:37:28 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del_two_dim_array(char ***arr)
{
	int		len;

	len = ft_len_two_dim_array(*arr);
	while (--len >= 0)
	{
		free((*arr)[len]);
		(*arr)[len] = NULL;
	}
	free(*arr);
}
