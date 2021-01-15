/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_the_type_struct.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:27:34 by rtacos            #+#    #+#             */
/*   Updated: 2020/07/08 20:34:28 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_create_typestruct(t_type *type)
{
	if ((type->types = ft_strdup("%diuoxXfcspeg\0")) == NULL)
		error(1, type->vl);
	if ((type->sizes = ft_strdup("hlLz\0")) == NULL)
		error(1, type->vl);
	ft_type_cleaning(type);
	type->print = 0;
	type->fd = 1;
	type->fall = 0;
}

void	ft_type_cleaning(t_type *type)
{
	type->width = 0;
	type->star_w = 0;
	type->precision = 0;
	type->star_p = 0;
	type->size = 0;
	type->type = '0';
	type->length = 0;
	type->cnt_zero = 0;
	type->f_plus = 0;
	type->f_space = 0;
	type->f_minus = 0;
	type->f_hash = 0;
	type->f_null = 0;
	type->f_pointer = 0;
	type->dot = 0;
}

void	ft_del_struct(t_type *type)
{
	ft_strdel(&type->types);
	ft_strdel(&type->sizes);
}
