#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <fcntl.h>

# define COREWAR_EXEC_MAGIC		0xea83f3

// void	ft_write_hex(char *str)
// {

// }

void	ft_ten_to_hex(int elem, int fd)
{
	char res;

	// printf("ELEM %d\n", elem);
	if (elem >= 16)
		ft_ten_to_hex(elem / 16, fd);
	res = elem % 16 + (elem % 16 < 10 ? '0' : 'a' - 10);
	write(fd, &res, 1);
}

void	ft_hex_to_char(char c, char *tmp)
{
	char	res;
	int		elem;

	elem = c;
	res = elem / 16;
	if (elem >= 16)
		ft_hex_to_char(res, tmp - 1);
	*tmp = elem % 16 + (elem % 16 < 10 ? '0' : 'a' - 10);
}

// void	ft_int_hex_to_char(int elem, char *tmp)
// {
// 	if (elem >= 16)
// 		ft_hex_to_char(elem / 16, tmp - 1);
// 	*tmp = elem % 16 + (elem % 16 < 10 ? '0' : 'a' - 10);
// }

int		ft_len_hex(int elem)
{
	int		len;

	len = 1;
	while (elem / 16)
	{
		len++;
		elem /= 16;
	}
	return (len);
}

int		ft_pow(int elem, int pow)
{
	int		i;
	int		res;

	i = 0;
	res = 1;
	while(++i <= pow)
		res *= elem;
	return (res);
}

void	ft_dec_to_bin(int n, char arr[8], int i)
{
	if (n >= 2)
		ft_dec_to_bin(n / 2, arr, i + 1);
	arr[i] = n % 2 + '0';
	// n %= 2;
	// printf("%d\n", n % 2);

}

void	ft_fill_zero(char *s, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		s[i] = '0';
		i++;
	}
}

void	ft_plus_one(char *arr)
{
	int		i;

	i = 8;
	while (--i >= 0)
	{
		if (arr[i] == '0')
		{
			arr[i] = '1';
			break;
		}
		else
			arr[i] = '0';
	}
}

int		main()
{
	// int	c = 12;
	char	arr[9] = "11001001";
	// char	*

	arr[8] = '\0';
	// ft_fill_zero(arr, 8);
	// ft_bzero(&arr, sizeof((char) * 8));
	// printf("%d\n", ft_pow(2, 6));
	// ft_dec_to_bin(19, arr, 0);
	ft_plus_one(arr);
	printf("%s\n", arr);
	// printf("%s\n", op_tab[2].name)
	// char	arr[8];
	// char	*tmp = arr;
	// // char arr[8];
	// // char *tmp = arr;
	// // char name[4] = "zork";
	// ft_bzero(arr, 8);
	// ft_int_hex_to_char(c, tmp + 2);
	// ft_strlen(arr);
	// ft_ten_to_hex(c, 1);
	// printf("LEN %d\n", ft_len_hex(c));
	// // printf("%s and %zu\n", arr, ft_strlen(arr));
	// int i = -1;
	// while (++i < 4)
	// {
	// 	ft_hex_to_char(name[i], tmp + 1);
	// 	tmp = tmp + 2;
	// }
	// printf("%d\n", ft_int_len(COREWAR_EXEC_MAGIC));
}

// int main()
// {
// 	int c = 'u';

// 	ft_ten_to_hex(c, 1);
// }