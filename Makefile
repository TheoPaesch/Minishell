NAME = minishell

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
RM		=	rm -rf

LIB		=	-lreadline -L$(LIBFT_DIR)
INC		=	-I includes

SRC_DIRS = ./srcs \
		   ./srcs/enviroment \
		   ./srcs/main \
		   ./srcs/prompt \
		   ./srcs/signal 
vpath %.c $(SRC_DIRS)

SRC = env_export_execution.c get_env.c \
	  main.c \
	  signal.c \
	  ft_strcspn.c \
	  ft_strspn.c \
	  prompt.c 

OBJ_DIR	=	obj
OBJ	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: 		$(NAME)

$(NAME):	$(LIBFT) $(OBJ_DIR) $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@ $(CFLAGS) $(LIB)

$(LIBFT):
				cd $(LIBFT_DIR) && make

$(OBJ_DIR):
				mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o:	%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
			cd $(LIBFT_DIR) && make clean
			$(RM) $(OBJ_DIR)

fclean:		clean
			cd $(LIBFT_DIR) && make fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re