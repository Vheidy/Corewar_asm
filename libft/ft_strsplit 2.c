/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:20:56 by vheidy            #+#    #+#             */
/*   Updated: 2019/09/17 20:36:01 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_num_word(char *s, char c)
{
	int i;
	int f;
	int num;

	i = 0;
	num = 0;
	while (s[i] != '\0')
	{
		f = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0' && f == 0)
		{
			f = 1;
			num++;
		}
		while (s[i] != c && s[i] != '\0' && f == 1)
			i++;
	}
	return (num);
}

static int		*ft_num_sb(char *s, char c, int nw)
{
	int *num;
	int j;
	int i;

	j = 0;
	i = 0;
	num = (int *)malloc(sizeof(int) * nw);
	if (!(num))
		return (NULL);
	while ((char)s[i] != '\0')
	{
		num[j] = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			num[j]++;
			i++;
		}
		j++;
	}
	return (num);
}

static void		ft_full(char **tmp, char *s, int *num, char c)
{
	int i;
	int j;
	int count;

	i = 0;
	count = ft_num_word(s, c);
	while (i < count && *s)
	{
		j = 0;
		while (*s == c && *s != '\0')
			s++;
		while (*s != c && *s != '\0' && j < num[i])
			tmp[i][j++] = *s++;
		tmp[i][j] = '\0';
		i++;
	}
	tmp[i] = (char*)0;
}

static char		**ft_free(char **tmp, int i)
{
	while (i-- >= 0)
		ft_strdel(&tmp[i]);
	free(tmp);
	tmp = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tmp;
	char	**lol;
	int		num;
	int		*num2;
	int		i;

	i = 0;
	if (!(s) || !(c))
		return (NULL);
	num = ft_num_word((char*)s, c);
	num2 = ft_num_sb((char*)s, c, num);
	tmp = (char **)malloc(sizeof(char *) * (num + 1));
	if (!(tmp))
		return (NULL);
	lol = tmp;
	while (i < num)
		if (!(*tmp++ = (char *)malloc(sizeof(char) * (num2[i++] + 1))))
			return (ft_free(tmp, i - 2));
	tmp = lol;
	ft_full(tmp, (char*)s, num2, c);
	return (tmp);
}
