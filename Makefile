NAME = asm

LIBFTA = $(LIB_DIR)libft.a
PRINTFA = $(PRINTF_DIR)libftprintf.a

HEADER = $(HEAD_DIR)asm.h
LIB_H = $(LIB_DIR)libft.h
PRINT_H = $(PRINTF_DIR)$(HEAD_DIR)ft_printf.h

LIB_DIR = libft/
HEAD_DIR = includes/
PRINTF_DIR = ft_printf/

HEAD = -I $(HEAD_DIR)
LIBFT_H = -I $(LIB_DIR)
PRINTF_H = -I $(PRINTF_DIR)$(HEAD_DIR)

COMP =	gcc -Wall -Werror -Wextra $(HEAD) $(LIBFT_H) $(PRINTF_H) -g

DIR = src_asm/

OBJ_DIR = obj/

SRCS = count_bytes_for_command.c ft_init_label.c ft_read.c \
		utilits.c count_bytes_for_command2.c ft_parse.c \
		ft_second_read.c ft_find_command.c ft_print_command.c main.c

OFILE =	$(SRCS:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR), $(OFILE))

all: lib $(NAME)

lib:
	@make -C $(LIB_DIR)
	@make -C $(PRINTF_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER) $(LIB_H) $(PRINT_H)
	@$(COMP) $(LIBFTA) $(PRINTFA) $(OBJ) -o $(NAME)
	@echo -------compile asm finish--------


$(OBJ_DIR)%.o: $(DIR)%.c $(HEADER)
	@$(COMP) -c $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@echo OBJECTS FILES HAS BEEN DELETED.

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@echo OBJECT FILES AND EXECUTABLE HAS BEEN DELETED.

re: fclean all