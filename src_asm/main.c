/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:41:27 by polina            #+#    #+#             */
/*   Updated: 2021/02/11 14:11:02 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_init_size_dir(t_asm *st)
{
	int		i;

	i = -1;
	while (++i < 16)
	{
		if (!ft_strcmp(st->op_tab[i].name, "zjmp") || !ft_strcmp(st->op_tab[i].name, "ldi") || 
		!ft_strcmp(st->op_tab[i].name, "sti") || !ft_strcmp(st->op_tab[i].name, "fork") ||
		!ft_strcmp(st->op_tab[i].name, "lldi") || !ft_strcmp(st->op_tab[i].name, "lfork"))
			st->op_tab[i].size_dir = 2;
		else
			st->op_tab[i].size_dir = 4;
	}
	
}

void	ft_init_op(t_op *op, char *name, int args, int needs_code)
{
	op->name = name;
	op->count_args = args;
	op->needs_code_args  = needs_code;
}

void	ft_init_op_tab(t_asm *st)
{
	ft_init_op(&st->op_tab[0], "live", 1, 0);
	ft_init_op(&st->op_tab[1], "ld", 2, 1);
	ft_init_op(&st->op_tab[2], "st", 2, 1);
	ft_init_op(&st->op_tab[3], "add", 3, 1);
	ft_init_op(&st->op_tab[4], "sub", 3, 1);
	ft_init_op(&st->op_tab[5], "and", 3, 1);
	ft_init_op(&st->op_tab[6], "or", 3, 1);
	ft_init_op(&st->op_tab[7], "xor", 3, 1);
	ft_init_op(&st->op_tab[8], "zjmp", 1, 0);
	ft_init_op(&st->op_tab[9], "ldi", 3, 1);
	ft_init_op(&st->op_tab[10], "sti", 3, 1);
	ft_init_op(&st->op_tab[11], "fork", 1, 0);
	ft_init_op(&st->op_tab[12], "lld", 2, 1);
	ft_init_op(&st->op_tab[13], "lldi", 3, 1);
	ft_init_op(&st->op_tab[14], "lfork", 1, 0);
	ft_init_op(&st->op_tab[15], "aff", 1, 1);
	ft_init_op(&st->op_tab[16], 0, 0, 0);
	ft_init_size_dir(st);
}

void	ft_del_struct(t_asm *st, char **name)
{
	t_label	*tmp;
	t_label *next;

	tmp = st->label;
	while (tmp)
	{
		next = tmp->next;
		ft_strdel(&tmp->name);
		free(tmp);
		tmp = next;
	}
	st->label = NULL;
	ft_strdel(name);
	ft_strdel(&st->name);
	ft_strdel(&st->comment);
	ft_strdel((char **)&st->exec_code);
}

int		main(int ac, char **av) {
	char	*name;
	t_asm	st;

	if (ac != 2)
		error("Wrong number of arguments", 0);
	ft_bzero(&st, sizeof(t_asm));
	name = ft_check_name(av[1]);
	if ((st.fd_orig = open(av[1], O_RDONLY)) == -1 || \
	(st.fd_res = open(name, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
		error("Failed to open file", 0);
	ft_init_op_tab(&st);
	ft_read(&st, name, av[1]);
	ft_del_struct(&st, &name);
	return (0);
}