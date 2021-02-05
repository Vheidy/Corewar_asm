/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bytes_for_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:28:02 by polina            #+#    #+#             */
/*   Updated: 2021/02/05 14:33:54 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"



int		ft_add_sub_args(char *args, t_asm *st)
{
	char	**arr_args;

	arr_args = ft_get_args(args, 3, st);
	if ((ft_check_type(arr_args[0], st) != 1) || (ft_check_type(arr_args[1], st) != 1) || \
	(ft_check_type(arr_args[2], st) != 1))
		error("Wrong type of argument ", st->string_num);
	ft_del_two_dim_array(&arr_args);
	return (5);
}

int		ft_st_args(char *args, t_asm *st)
{
	int		cod_sec;
	char	**arr_args;

	arr_args = ft_get_args(args, 2, st);
	cod_sec = ft_check_type(arr_args[1], st);
	if (ft_check_type(arr_args[0], st) != 1 || \
	cod_sec == 10)
		error("Wrong type of argument ", st->string_num);
	ft_del_two_dim_array(&arr_args);
	return (ft_count_type_byte(cod_sec, 1) + 3);
}

int		ft_ld_lld_args(char *args, t_asm *st)
{
	int		cod_first;
	char	**arr_args;

	arr_args = ft_get_args(args, 2, st);
	if ((cod_first = ft_check_type(arr_args[0], st)) == 1 || \
	ft_check_type(arr_args[1], st) != 1)
		error("Wrong type of argument ", st->string_num);
	ft_del_two_dim_array(&arr_args);
	return (ft_count_type_byte(cod_first, 1) + 3);
}

int		ft_one_dir_args(char *name, char *args, t_asm *st)
{
	char	**arr_args;

	arr_args = ft_get_args(args, 1, st);
	if (ft_check_type(arr_args[0], st) != 10)
		error("Wrong type of argument ", st->string_num);
	ft_del_two_dim_array(&arr_args);
	if (!ft_strcmp(name, "live"))
		return (5);
	return (3);
}
