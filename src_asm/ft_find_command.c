/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:29:53 by polina            #+#    #+#             */
/*   Updated: 2021/01/26 16:38:40 by polina           ###   ########.fr       */
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
	error("Wrong type of arguments", 0);
	return (0);
}

char	**ft_get_args(char *args, int count_arg, t_asm *st)
{
	char	**tmp;
	char	**res;
	int		len;

	tmp = ft_strsplit(args, SEPARATOR_CHAR);
	if ((len = ft_len_two_dim_array(tmp)) != count_arg)
		error("Wrong number of arguments ", st->string_num);
	if (!(res = malloc(sizeof(char*) * (len + 1))))
		error("Failed to allocate memory", 0);
	res[len] = NULL;
	while (--len >= 0)
		res[len] = ft_del_space(tmp[len], st);
	ft_del_two_dim_array(&tmp);
	return (res);
}

void	ft_check_args_char(char *str, t_asm *st)
{
	if (*str == LABEL_CHAR)
	{
		str++;
		while (*str)
		{
			if (!ft_strchr(LABEL_CHARS, *str))
				error("Label names contains invalid charecters ", st->string_num);
			str++;
		}
	}
	else if (ft_isdigit(*str))
	{
		while (*str)
		{
			if (!ft_isdigit(*str))
				error("Number names contains invalid charecters" , st->string_num);
			str++;
		}
	}
}

int		ft_check_type(char *str, t_asm *st)
{
	if (*str == DIRECT_CHAR)
	{
		str++;
		ft_check_args_char(str, st);
		return (10);
	}
	else if (ft_isdigit(*str) || *str == '-' || *str == LABEL_CHAR)
	{
		ft_check_args_char(str, st);
		return (11);
	}
	else if (*str == 'r')
	{
		str++;
		if (ft_strlen(str) > 2 || !ft_atoi(str))
			error("Wrong register value ", st->string_num);
		while (*str)
			if (!ft_isdigit(*str++))
				error("Wrong register value ", st->string_num);
		return (1);
	}
	error("Wrong type of arguments ", 0);
	return (0);
}

int		ft_find_command(char *name, char *args, t_asm *st)
{
	if (!ft_strcmp(name, "live") || !ft_strcmp(name, "zjmp") || \
	!ft_strcmp(name, "fork") || !ft_strcmp(name, "lfork"))
		return (ft_one_dir_args(name, args, st));
	else if (!ft_strcmp(name, "ld") || !ft_strcmp(name, "lld"))
		return (ft_ld_lld_args(args, st));
	else if (!ft_strcmp(name, "st"))
		return (ft_st_args(args, st));
	else if (!ft_strcmp(name, "add") || !ft_strcmp(name, "sub"))
		return (ft_add_sub_args(args, st));
	else if (!ft_strcmp(name, "and") || !ft_strcmp(name, "or") || \
	!ft_strcmp(name, "xor"))
		return (ft_logical_args(args, st));
	else if (!ft_strcmp(name, "ldi") || !ft_strcmp(name, "lldi"))
		return (ft_ldi_lldi_args(args, st));
	else if (!ft_strcmp(name, "sti"))
		return (ft_sti_args(args, st));
	else if (!ft_strcmp(name, "aff"))
		return (ft_aff_args(args, st));
	error("Wrong name of command ", st->string_num);
	return (0);
}
