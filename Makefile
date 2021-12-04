NAME	= libftprintf.a

SRC	= ft_printf.c	ft_printf_utils.c

HEADER	= ft_printf.h
OBJ	= $(putsubst %.c, %.o, $(SRC))

CFLAGS	= -Wall -Wextra -Werror -I$(HEADER)
CC = gcc

.PHONY: all clean fclean re

all	: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o	: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)

fclean	: clean
	@$(RM) $(NAME)

re	: fclean all
