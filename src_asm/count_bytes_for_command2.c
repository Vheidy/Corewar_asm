/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bytes_for_command2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:29:15 by polina            #+#    #+#             */
/*   Updated: 2021/01/26 17:04:22 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_logical_args(char *args, t_asm *st)
{
	char	**arr_args;
	int		res;

	arr_args = ft_get_args(args, 3, st);
	if (ft_check_type(arr_args[2], st) != 1)
		error("Wrong type of argument ", st->string_num);
	res = 3 + ft_count_type_byte(ft_check_type(arr_args[0], st), 1) + \
	ft_count_type_byte(ft_check_type(arr_args[1], st), 1);
	ft_del_two_dim_array(&arr_args);
	return (res);
}

int		ft_aff_args(char *args, t_asm *st)
{
	char	**arr_args;

	arr_args = ft_get_args(args, 1, st);
	if (ft_check_type(arr_args[0], st) != 1)
		error("Wrong type of argument ", st->string_num);
	ft_del_two_dim_array(&arr_args);
	return (3);
}

int		ft_sti_args(char *args, t_asm *st)
{
	int		cod_third;
	int		res;
	char	**arr_args;

	arr_args = ft_get_args(args, 3, st);
	if (ft_check_type(arr_args[0], st) != 1)
		error("Wrong type of argument ", st->string_num);
	if ((cod_third = ft_check_type(arr_args[2], st)) == 11)
		error("Wrong type of argument ", st->string_num);
	res = 3 + ft_count_type_byte(ft_check_type(arr_args[1], st), 0) + ft_count_type_byte(cod_third, 0);
	ft_del_two_dim_array(&arr_args);
	return (res);
}

int		ft_ldi_lldi_args(char *args, t_asm *st)
{
	int		cod_second;
	char	**arr_args;
	int		res;

	arr_args = ft_get_args(args, 3, st);
	if ((cod_second = ft_check_type(arr_args[1], st)) == 11 || \
	ft_check_type(arr_args[2], st) != 1)
		error("Wrong type of argument ", st->string_num);
	res = 3 + ft_count_type_byte(ft_check_type(arr_args[0], st), 0) + \
	ft_count_type_byte(cod_second, 0);
	ft_del_two_dim_array(&arr_args);
	return (res);
}
