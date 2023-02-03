NAME_SERVER	=	mandatory/server
NAME_CLIENT	=	mandatory/client

NAME_SERVER_BONUS	=	bonus/server_bonus
NAME_CLIENT_BONUS	=	bonus/client_bonus

LIB			=	libft/libft.a
PRINT		=	ft_printf/libftprintf.a

SRC_SERVER	=	mandatory/server.c
OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

SRC_CLIENT	=	mandatory/client.c
OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

SRC_SERVER_BONUS	=	bonus/server_bonus.c
OBJ_SERVER_BONUS	=	$(SRC_SERVER_BONUS:.c=.o)

SRC_CLIENT_BONUS	=	bonus/client_bonus.c
OBJ_CLIENT_BONUS	=	$(SRC_CLIENT_BONUS:.c=.o)

SRC_LIB		=	libft/ft_isdigit.c libft/ft_strlen.c libft/ft_strchr.c libft/ft_atoi.c\
				libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_strnstr.c

SRC_PRINT	=	ft_printf/ft_putchar.c ft_printf/ft_putstr.c ft_printf/ft_putnbr_add.c \
				ft_printf/ft_putnbr.c ft_printf/ft_putnbr_unsigned.c ft_printf/ft_putnbr_hlow.c \
				ft_printf/ft_putnbr_hupp.c ft_printf/ft_printf.c

CC			=	@cc
CFLAGS		=	-Wall -Werror -Wextra

all		:	$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER)	:	$(OBJ_SERVER) $(LIB) $(PRINT)
	@printf "\e[38;5;236m \n ⚡︎⚡︎⚡︎⚡︎⚡︎⚡︎ COMPILING ⚡︎⚡︎⚡︎⚡︎⚡︎⚡︎\n\e[0m\n"
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIB) $(PRINT) -o $@
	@printf "\e[38;5;216m→	successfully server build ✔︎\e[0m\n"
$(NAME_CLIENT)	:	$(OBJ_CLIENT) $(LIB) $(PRINT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIB) $(PRINT) -o $@
	@printf "\e[38;5;216m→	successfully client build ✔︎\e[0m\n"

$(NAME_SERVER_BONUS) :	$(OBJ_SERVER_BONUS) $(LIB) $(PRINT)
	@printf "\e[38;5;236m \n ⚡︎⚡︎⚡︎⚡︎⚡︎⚡︎ COMPILING BONUS ⚡︎⚡︎⚡︎⚡︎⚡︎⚡︎\n\e[0m\n"
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(LIB) $(PRINT) -o $@
	@printf "\e[38;5;216m→	successfully server_bonus build ✔︎\e[0m\n"
$(NAME_CLIENT_BONUS) :	$(OBJ_CLIENT_BONUS) $(LIB) $(PRINT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(LIB) $(PRINT) -o $@
	@printf "\e[38;5;216m→	successfully client_bonus build ✔︎\e[0m\n"

$(LIB)	:	$(SRC_LIB)
	@make -C libft

$(PRINT):	$(SRC_PRINT)
	@make -C ft_printf

bonus	:	$(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

clean	:
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
	@make -C libft clean
	@make -C ft_printf clean
	@printf "\e[38;5;206m→	Objects files deleted 🗑\e[0m\n"

fclean	: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	@make -C libft fclean
	@make -C ft_printf fclean
	@printf "\e[38;5;206m→	All files was deleted 🗑\e[0m\n"

re	: fclean all
