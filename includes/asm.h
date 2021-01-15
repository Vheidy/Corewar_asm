/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:40:38 by polina            #+#    #+#             */
/*   Updated: 2021/01/14 21:01:31 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct		s_label
{
	int				byte_pos;
	char			*name;
	struct s_label	*next;
}					t_label;

typedef struct	s_op
{
	char *name;
	int count_args;
	int needs_code_args;
	int size_dir;
}				t_op;

typedef struct		s_asm
{
	t_label			*label;
	t_op			op_tab[17];
	int				curr_pos;
	int				count_bytes;
	char			*comment;
	char			*name;
	int				fd_orig;
	int				fd_res;
}					t_asm;

void	error();
void	ft_read(t_asm *st, char *name);
int		ft_find_command(char *name, char *args);
char	*ft_create_name_label(char *colon, char **buf);
void	ft_add_label(char *name, t_asm *st);
int		ft_find_space(char c);
int		ft_len_hex(int elem);
void	ft_second_read(t_asm *st);
void	ft_print_null(t_asm *st, int size);
void	ft_write_hex(int elem, int fd);
char	**ft_get_args(char *args, int count_arg);