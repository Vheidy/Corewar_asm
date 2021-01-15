/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:29:53 by polina            #+#    #+#             */
/*   Updated: 2020/12/30 21:29:42 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_count_type_byte(int arg, int flag)
{
	if (arg == 10 && flag)
		return (4);
	else if (arg == 10 && !flag)
		return (2);
	else if (arg == 1)
		return (1);
	else if (arg == 11)
		return (2);
	error();
	return (0);
}

int		ft_len_array(char **arr)
{
	int		len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

char	*ft_del_space(char *str)
{
	char	*start;
	char	*end;

	start = str;
	while (ft_find_space(*start))
		start++;
	end = start;
	if (!*start)
		error();
	while (*end && !ft_find_space(*end))
		end++;
	return (ft_strsub(start, 0, end - start));
}

void	ft_del_array(char ***arr)
{
	char	**tmp;
	char	**tmp_next;
	int		len;

	len = ft_len_array(*arr);
	while (--len >= 0)
	{
		free((*arr)[len]);
		(*arr)[len] = NULL;
	}
	free(*arr);
}

char	**ft_get_args(char *args, int count_arg)
{
	char	**tmp;
	char	**res;
	int		len;

	tmp = ft_strsplit(args, SEPARATOR_CHAR);
	if ((len = ft_len_array(tmp)) != count_arg)
		error();
	res = malloc(sizeof(char*) * (len + 1));
	res[len] = NULL;
	while (--len >= 0)
		res[len] = ft_del_space(tmp[len]);
	ft_del_array(&tmp);
	return (res);
}

void	ft_check_args_char(char *str)
{
	if (*str == LABEL_CHAR)
	{
		str++;
		while (*str)
		{
			if (!ft_strchr(LABEL_CHARS, *str))
				error();
			str++;
		}
	}
	else if (ft_isdigit(*str))
	{
		while (*str)
		{
			if (!ft_isdigit(*str))
				error();
			str++;
		}
	}
}

int		ft_check_type(char *str)
{
	if (*str == DIRECT_CHAR)
	{
		str++;
		ft_check_args_char(str);
		return (10);
	}
	else if (ft_isdigit(*str) || *str == '-' || *str == LABEL_CHAR)
	{
		ft_check_args_char(str);
		return (11);
	}
	else if (*str == 'r')
	{
		if (ft_strlen(str) > 3 || !ft_strcmp(str, "r00"))
			error();
		str++;
		while (*str)
			if (!ft_isdigit(*str++))
				error();
		return (1);
	}
	error();
	return (0);
}

int		ft_aff_args(char *args)
{
	char	**arr_args;

	arr_args = ft_get_args(args, 1);
	if (ft_check_type(arr_args[0]) != 1)
		error();
	ft_del_array(&arr_args);
	return (3);
}

int		ft_sti_args(char *args)
{
	int		cod_third;
	int		res;
	char	**arr_args;

	arr_args = ft_get_args(args, 3);
	if (ft_check_type(arr_args[0]) != 1)
		error();
	// printf("ok\n");
	if ((cod_third = ft_check_type(arr_args[2])) == 11)
		error();
	res = 3 + ft_count_type_byte(ft_check_type(arr_args[1]), 0) + ft_count_type_byte(cod_third, 0);
	ft_del_array(&arr_args);
	return (res);
}

int		ft_ldi_lldi_args(char *args)
{
	int		cod_second;
	char	**arr_args;
	int		res;

	arr_args = ft_get_args(args, 3);
	if ((cod_second = ft_check_type(arr_args[1])) == 11)
		error();
	if (ft_check_type(arr_args[2]) != 1)
		error();
	res = 3 + ft_count_type_byte(ft_check_type(arr_args[0]), 0) + \
	ft_count_type_byte(cod_second, 0);
	ft_del_array(&arr_args);
	return (res);
}

int		ft_logical_args(char *args)
{
	char	**arr_args;
	int		res;

	arr_args = ft_get_args(args, 3);
	if (ft_check_type(arr_args[2]) != 1)
		error();
	res = 3 + ft_count_type_byte(ft_check_type(arr_args[0]), 1) + \
	ft_count_type_byte(ft_check_type(arr_args[1]), 1);
	ft_del_array(&arr_args);
	return (res);
}

int		ft_add_sub_args(char *args)
{
	char	**arr_args;

	arr_args = ft_get_args(args, 3);
	if ((ft_check_type(arr_args[0]) != 1) || (ft_check_type(arr_args[1]) != 1) || \
	(ft_check_type(arr_args[2]) != 1))
		error();
	ft_del_array(&arr_args);
	return (5);
}

int		ft_st_args(char *args)
{
	int		cod_sec;
	char	**arr_args;

	arr_args = ft_get_args(args, 2);
	if (ft_check_type(arr_args[0]) != 1)
		error();
	if ((cod_sec = ft_check_type(arr_args[1])) == 10)
		error();
	ft_del_array(&arr_args);
	return (ft_count_type_byte(cod_sec, 1) + 3);
}

int		ft_ld_lld_args(char *args)
{
	int		cod_first;
	char	**arr_args;

	arr_args = ft_get_args(args, 2);
	if ((cod_first = ft_check_type(arr_args[0])) == 1)
		error();
	if (ft_check_type(arr_args[1]) != 1)
		error();
	ft_del_array(&arr_args);
	return (ft_count_type_byte(cod_first, 1) + 3);
}

int		ft_one_dir_args(char *name, char *args)
{
	char	**arr_args;

	arr_args = ft_get_args(args, 1);
	if (ft_check_type(arr_args[0]) != 10)
		error();
	ft_del_array(&arr_args);
	if (!ft_strcmp(name, "live"))
		return (5);
	return (3);
}

int		ft_find_command(char *name, char *args)
{
	if (!ft_strcmp(name, "live") || !ft_strcmp(name, "zjmp") || \
	!ft_strcmp(name, "fork") || !ft_strcmp(name, "lfork"))
		return (ft_one_dir_args(name, args));
	else if (!ft_strcmp(name, "ld") || !ft_strcmp(name, "lld"))
		return (ft_ld_lld_args(args));
	else if (!ft_strcmp(name, "st"))
		return (ft_st_args(args));
	else if (!ft_strcmp(name, "add") || !ft_strcmp(name, "sub"))
		return (ft_add_sub_args(args));
	else if (!ft_strcmp(name, "and") || !ft_strcmp(name, "or") || \
	!ft_strcmp(name, "xor"))
		return (ft_logical_args(args));
	else if (!ft_strcmp(name, "ldi") || !ft_strcmp(name, "lldi"))
		return (ft_ldi_lldi_args(args));
	else if (!ft_strcmp(name, "sti"))
		return (ft_sti_args(args));
	else if (!ft_strcmp(name, "aff"))
		return (ft_aff_args(args));
	error();
	return (0);
}
