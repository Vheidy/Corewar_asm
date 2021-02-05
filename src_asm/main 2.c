/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:41:27 by polina            #+#    #+#             */
/*   Updated: 2021/01/13 20:46:10 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error()
{
	write(1, "ERROR\n", 6);
	exit(0);
}

/*
 ** Проверка имени файла на нужное расширение и создание имени с расширением .cor
*/
char	*ft_check_name(char *name)
{
	char	*point;
	char	*tmp_name;
	char	*new_name;

	if (!(point = ft_strchr(name, '.')))
		error();
	tmp_name = ft_strsub(name, 0, point - name);
	point++;
	if (ft_strcmp(point, "s"))
		error();
	new_name = ft_strjoin(tmp_name, ".cor");
	free(tmp_name);
	return (new_name);
}

void	ft_print_labels(t_asm *st)
{
	t_label *tmp = st->label;
	while (tmp)
	{
		printf("Name: %s\nBytes: %d\n", tmp->name, tmp->byte_pos);
		printf("----\n");
		tmp = tmp->next;
	}
	printf("%d\n", st->count_bytes);
}

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

int		main(int ac, char **av) {
	char	*name;
	t_asm	st;

	if (ac != 2)
		error();
	ft_bzero(&st, sizeof(t_asm));
	// write(1, COREWAR_EXEC_MAGIC, 1);
	// printf("%d\n", COREWAR_EXEC_MAGIC);
	// printf("ok\n");
	name = ft_check_name(av[1]);
	if ((st.fd_orig = open(av[1], O_RDONLY)) == -1 || \
	(st.fd_res = open(name, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
		error();
	ft_init_op_tab(&st);
	// printf("%s\n", st.op_tab[16].name);
	ft_read(&st, name);
	// free(name);
	// ft_print_labels(&st);
	// printf("%d %d\n", st.fd_orig, st.fd_res);
}