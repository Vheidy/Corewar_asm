/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:14:45 by polina            #+#    #+#             */
/*   Updated: 2021/01/14 22:03:34 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_bin_to_hex(char *arr[8], t_asm *st, int size)
{
	int		res;
	int		i;

	i = 8;
	res = 0;
	while (--i >= 0)
		if (arr[i] == '1')
			res += ft_pow(2, 7 - i);
	ft_print_null(st, size - ft_len_hex(res));
	ft_write_hex(res, st->fd_res);
}

void	ft_print_reg(char *arg, t_asm *st)
{
	int		res;

	res = ft_atoi(++arg);
	ft_print_null(st, 2 - ft_len_hex(res));
	ft_write_hex(res, st->fd_res);
}

void	ft_dec_to_bin(int n, char arr[8], int i)
{
	if (n >= 2)
		ft_dec_to_bin(n / 2, arr, i + 1);
	arr[i] = n % 2 + '0';
}

void	ft_fill_zero(char *s, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		s[i] = '0';
		i++;
	}
}

void	ft_plus_one(char *arr)
{
	int		i;

	i = 8;
	while (--i >= 0)
	{
		if (arr[i] == '0')
		{
			arr[i] = '1';
			break;
		}
		else
			arr[i] = '0';
	}
}

void	ft_print_negative(int elem, t_asm *st)
{
	char	arr[8];
	int		i;

	i = -1;
	ft_fill_zero(arr, 8);
	ft_dec_to_bin(elem * -1, arr, 0);
	while (++i < 8)
	{
		if (arr[i] == '0');
			arr[i] = '1';
		else
			arr[i] = '0';
	}
	ft_plus_one(arr);
	ft_bin_to_hex(arr, st, 4);
}

void	ft_print_dir_ind(char *arg, t_asm *st, int index, int fl)
{
	int		res;

	if (++(*arg) == LABEL_CHAR)
		res = ft_find_label(arg)->byte_pos - st->curr_pos;
	else
		res = ft_atoi(arg);
	if (res < 0)
		ft_print_negative(res, st);
	if (fl)
		ft_print_null(st, 2 * st->op_tab[index].size_dir - ft_len_hex(res));
	else
		ft_print_null(st, 4 - ft_len_hex(res));
	ft_write_hex(res, st->fd_res);
}

void	ft_print_args(char **tmp, t_asm *st, index)
{
	int		i;
	int		tmp;

	i = -1;
	while (++i < st->op_tab[index].count_args)
	{
		tmp = ft_check_type(tmp[i]);
		if (tmp = 1)
			ft_print_reg(tmp[i], st);
		else if (tmp = 10)
			ft_print_dir_ind(tmp[i], st, index, 1);
		else
			ft_print_dir_ind(tmp[i], st, index, 0);
	}
}

void	ft_print_command(t_asm *st, int index, char *args)
{
	char	**tmp;
	char	arr[8];
	int		i;
	int		res;

	i = -1;
	ft_fill_zero(arr, 8);
	ft_print_null(st, (2 - ft_len_hex(index + 1));
	ft_write_hex(index + 1, st->fd_res);
	tmp = ft_get_args(args, st->op_tab[index].count_args);
	if (st->op_tab[index].needs_code_args)
	{
		while (++i < st->op_tab[index].count_args)
			if ((res = ft_check_type(tmp[i])) == 1)
				arr[i] = ft_itoa(++res, 1);
			else
				arr[i] = ft_itoa(++res, 0);
		ft_bin_to_hex(&arr, st, 2);
	}
	ft_print_args(tmp, st, index);
}

void	ft_select_command(t_asm *st, char *name, char *args)
{
	int		i;

	i = -1;
	while (++i < 17)
	{
		if (!ft_strcmp(st->op_tab[i].name, name))
			ft_print_command(st, i, args);
	}
}