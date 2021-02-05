/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:14:45 by polina            #+#    #+#             */
/*   Updated: 2021/01/26 16:45:50 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_set_exec_code(t_asm *st, int elem, int size)
{
	unsigned char *point;

	if (st->little_endian)
		elem = ft_convert_to_big_endian(elem);
	point = (unsigned char *)&elem;
	point += sizeof(int) - size;
	while (size-- > 0)
	{
		st->exec_code[st->index++] = *point;
		point++;
	}
}

void	ft_print_dir_ind(char *arg, t_asm *st, int index, int fl)
{
	int		res;

	if (*arg == LABEL_CHAR)
		res = ft_find_label(arg, st)->byte_pos - st->curr_pos;
	else
		res = ft_atoi(arg);
	if (fl)
		ft_set_exec_code(st, res, st->op_tab[index].size_dir);
	else
		ft_set_exec_code(st, res, 2);
}

void	ft_print_args(char **tmp, t_asm *st, int index)
{
	int		i;
	int		type;
	int		res;

	i = -1;
	while (++i < st->op_tab[index].count_args)
	{
		type = ft_check_type(tmp[i], st);
		if (type == 1)
		{
			res = ft_atoi(tmp[i] + 1);
			ft_set_exec_code(st, res, 1);
		}
		else if (type == 10)
			ft_print_dir_ind(tmp[i] + 1, st, index, 1);
		else
			ft_print_dir_ind(tmp[i], st, index, 0);
	}
}

void	ft_fill_args(int count, int arg, int *num)
{
	int		shift;

	shift = 8 - count * 2;
	if (arg == 1 || arg == 11)
		*num |= 1 << shift;
	if (arg == 10 || arg == 11)
		*num |= 1 << (shift + 1);
}

void	ft_print_command(t_asm *st, int index, char *args)
{
	char	**tmp;
	int		count;
	int		res;
	int		type;

	count = -1;
	res = index + 1;
	st->exec_code[st->index++] = res;
	res = 0;
	tmp = ft_get_args(args, st->op_tab[index].count_args, st);
	if (st->op_tab[index].needs_code_args)
	{
		while (++count < st->op_tab[index].count_args)
		{
			type = ft_check_type(tmp[count], st);
			ft_fill_args(count + 1, type, &res);
		}
		st->exec_code[st->index++] = res;
	}
	ft_print_args(tmp, st, index);
}
