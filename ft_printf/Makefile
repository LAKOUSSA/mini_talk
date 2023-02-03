NAME		=	libftprintf.a

CC			=	@cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	ft_putchar.c ft_putstr.c ft_putnbr_add.c ft_putnbr.c ft_putnbr_unsigned.c ft_putnbr_hlow.c ft_putnbr_hupp.c ft_printf.c

OBJ			=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	@ar -rc $(NAME) $(OBJ)

clean	:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean	: clean
	@rm -f $(NAME)

re	: fclean all
