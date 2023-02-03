NAME		=	libft.a

SRCS		=	ft_isdigit.c ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c

OBJ			=	$(SRCS:.c=.o)

CC			=	@cc
CFLAGS		=	-Wall -Werror -Wextra

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	@ar -rc $(NAME) $(OBJ)

clean	:
	@rm -f $(OBJ)

fclean	: clean
	@rm -f $(NAME)

re	: fclean all bonus
