NAME = minishell.a

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
MAKE	=	make
RM		=	rm -rf

LIB		=	-lreadline -lft -L$(LIBFT_DIR)
INC		=	-I includes

SRC_DIRS = ./srcs/enviroment \
		   ./srcs/main \
		   ./srcs/prompt \
		   ./srcs/signal \
		   ./srcs/mem_man \
		   ./srcs/parsing \
		   ./srcs/pipes \
		   ./srcs/tokenizer
vpath %.c $(SRC_DIRS)

SRC = env_export_execution.c get_env.c \
	  main.c \
	  ft_del_mem.c ft_free.c ft_malloc.c \
	  parsing.c \
	  pipes.c \
	  signal.c \
	  ft_strcspn.c \
	  ft_strjoinall.c \
	  ft_strspn.c \
	  prompt.c \
	  ft_strtok.c tokenizer.c

OBJ_DIR	=	obj
OBJ	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))obj

all: 		$(NAME)

$(NAME):	$(LIBFT) $(OBJ_DIR) $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $@ $(CFLAGS) $(LIB)

$(LIBFT):
				cd $(LIBFT_DIR) && $(MAKE) clean

$(OBJ_DIR):
				mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o:	%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
			cd $(LIBFT_DIR) && $(MAKE) clean
			$(RM) $(OBJ_DIR)

fclean:		clean
			cd $(LIBFT_DIR) && $(MAKE) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re