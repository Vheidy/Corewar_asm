/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:40:38 by polina            #+#    #+#             */
/*   Updated: 2021/02/05 14:34:47 by polina           ###   ########.fr       */
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
	int				little_endian;
	int				header_end;
	int				string_num;
	unsigned char	*exec_code;
	int				index;
	int				curr_pos;
	int				count_bytes;
	char			*comment;
	char			*name;
	int				fd_orig;
	int				fd_res;
}					t_asm;

/*
 ** ft_parse.c
*/
char	*ft_check_name(char *name);
void	ft_parse_name_or_comment(t_asm *st, char *res, char **buf);
/*
 ** utilits.c
*/
void	error(char *str, int num_string);
int		ft_convert_to_big_endian(int elem);
char	*ft_del_space(char *str, t_asm *st);
int		ft_find_space(char c);
int		ft_check_alt_comment(char *start);
/*
 ** ft_find_command.c
*/
char	**ft_get_args(char *args, int count_arg, t_asm *st);
int		ft_check_type(char *str, t_asm *st);
int		ft_find_command(char *name, char *args, t_asm *st);
int		ft_count_type_byte(int arg, int flag);
/*
 ** ft_init_label.c
*/
char	*ft_create_name_label(char *colon, char **buf, t_asm *st);
void	ft_add_label(char *name, t_asm *st);
t_label	*ft_find_label(char *name, t_asm *st);
/*
 ** ft_second_read.c
*/
void	ft_second_read(t_asm *st);
void	ft_check_end_line(t_asm *st);
void	ft_select_command(t_asm *st, char *name, char *args);
/*
 ** ft_print_command.c
*/
void	ft_print_command(t_asm *st, int index, char *args);
/*
 ** ft_read.c
*/
void	ft_read_command(char *command, t_asm *st, int fl);
void	ft_read(t_asm *st, char *name, char *old_name);
/*
 ** ft_count_bytes_for_command/2.c
*/
int		ft_add_sub_args(char *args, t_asm *st);
int		ft_st_args(char *args, t_asm *st);
int		ft_ld_lld_args(char *args, t_asm * st);
int		ft_one_dir_args(char *name, char *args, t_asm *st);
int		ft_logical_args(char *args, t_asm *st);
int		ft_aff_args(char *args, t_asm *st);
int		ft_sti_args(char *args, t_asm *st);
int		ft_ldi_lldi_args(char *args, t_asm *st);
