# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vheidy <vheidy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 21:38:06 by vheidy            #+#    #+#              #
#    Updated: 2020/12/03 20:09:03 by vheidy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_strjoin_free_all.c ft_free_delim.c ft_int_len.c \
get_next_line.c ft_strjoin_free.c ft_lstmap.c ft_atoi.c \
ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
ft_lstiter.c ft_lstnew.c ft_memalloc.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c \
ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
ft_strtrim.c ft_tolower.c ft_toupper.c ft_base_intlen.c \
ft_power.c ft_intlen.c ft_itoa_base.c ft_itoa_unsig_base.c \
ft_atoi_base.c ft_put_n_line_char.c

HEADER = libft.h

COMP =	gcc -Wall -Werror -Wextra

OFILE = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFILE) $(HEADER)
	@ar -rc $(NAME) $(OFILE)
	@echo -------compile library finish----------

$(OFILE): %.o: %.c $(HEADER)
	@$(COMP) -c $< -o $@

clean:
	@rm -f $(OFILE)

fclean: clean
	@rm -f $(NAME)

re: fclean all
