/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polina <polina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:30:49 by polina            #+#    #+#             */
/*   Updated: 2020/12/30 21:14:58 by polina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label	*ft_init_label(char *name, int bytes)
{
	t_label *new_label;

	new_label = malloc(sizeof(t_label));
	new_label->name = name;
	// printf("ok\n");
	new_label->byte_pos = bytes;
	new_label->next = NULL;
	return (new_label);
}

void	ft_add_label(char *name, t_asm *st)
{
	t_label *tmp;
	
	if (!st->label)
	{
		
		st->label = ft_init_label(name, st->count_bytes);
	// printf("ok\n");
	}
	else
	{
		tmp = st->label;
		while (tmp->next)
		{
			if (!ft_strcmp(tmp->name, name))
				error();
			tmp = tmp->next;
		}
		tmp->next = ft_init_label(name, st->count_bytes);
	}
	// printf("ok\n");
}

char	*ft_create_name_label(char *colon, char **buf)
{
	char	*name;
	char	*start;
	int		i;

	start = *buf;
	i = 0;
	while (*start && (*start == ' ' || *start == '\f' || *start == '\v' \
			|| *start == '\t' || *start == '\r'))
		start++;
	name = ft_strsub(start, 0, colon - start);
	while (name[i])
		if (!ft_strchr(LABEL_CHARS, name[i++]))
			error();
	// printf("%s\n", name);
	return (name);
}
