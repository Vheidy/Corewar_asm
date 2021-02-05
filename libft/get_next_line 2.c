/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:24:49 by vheidy            #+#    #+#             */
/*   Updated: 2020/10/11 20:31:31 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*ft_create(int fd)
{
	t_gnl	*list;

	if (!(list = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	list->fd = fd;
	list->data = NULL;
	list->next = NULL;
	return (list);
}

t_gnl	*ft_check(int fd, t_gnl **list)
{
	t_gnl	*tmp;
	t_gnl	*prev;

	if (!(*list))
		return ((*list = ft_create(fd)));
	tmp = *list;
	while (tmp && tmp->fd != fd)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
	{
		tmp = ft_create(fd);
		prev->next = tmp;
	}
	return (tmp);
}

int		ft_new_line(char **line, char **s1, size_t size)
{
	char *tmp;

	tmp = *s1;
	*line = ft_strsub(tmp, 0, size);
	if (!(*s1 = ft_strsub(tmp, size + 1, ft_strlen(tmp) - size - 1)))
	{
		ft_strdel(&tmp);
		return (-1);
	}
	if (!*s1[0])
	{
		free(*s1);
		*s1 = NULL;
	}
	ft_strdel(&tmp);
	return (1);
}

int		ft_final_check(char **s, char **line)
{
	*line = *s;
	*s = NULL;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*b_list;
	t_gnl			*list;
	char			*tmp;
	int				red;
	char			buf[BUFF_SIZE + 1];

	if (read(fd, buf, 0) < 0 || line == NULL)
		return (-1);
	if (!(list = ft_check(fd, &b_list)))
		return (-1);
	while ((red = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[red] = '\0';
		if (!(list->data = ft_strjoin_free(list->data, buf, 1, 0)))
			return (-1);
		if (list->data && (tmp = ft_strchr(list->data, '\n')))
			return (ft_new_line(line, &list->data, (tmp - list->data)));
	}
	if (list->data && (tmp = ft_strchr(list->data, '\n')))
		return (ft_new_line(line, &list->data, (tmp - list->data)));
	if (list->data)
		return (ft_final_check(&list->data, line));
	*line = NULL;
	return (0);
}
