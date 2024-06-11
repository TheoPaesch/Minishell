NAME = minishell

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIB = -lreadline -L$(LIBFT_DIR)
INC = -I includes

SRC_DIRS = ./srcs \
           ./srcs/environment \
           ./srcs/main \
           ./srcs/prompt \
           ./srcs/signal \
           ./srcs/parsing \
           ./srcs/tokenizer \
		   ./srcs/execution

vpath %.c $(SRC_DIRS)

SRC = env_export_execution.c \
      get_env.c \
      main.c \
      splash.c \
      signal.c \
      ft_strcspn.c \
      ft_strspn.c \
      ft_strtok.c \
      prompt.c \
      constructors.c \
      nullterm_utils.c \
      nullterm.c \
      parse_utils.c \
      parse_utils_2.c \
      get_token.c \
      scan_skip_ws.c \
      execute.c \
      safe_utils.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# COLORS
BLUE = \033[0;34m
GREEN = \033[0;32m
NO_COLOR = \033[0m

all: start_compile $(NAME) end_compile

start_compile:
	@printf "$(BLUE)Compiling Minishell...$(NO_COLOR)\n"
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB)
	@printf "$(GREEN)SUCCESS - $(NAME) has been successfully compiled$(NO_COLOR)\n"

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC) && printf "$(GREEN)Compiled $(notdir $<)$(NO_COLOR)\n" || printf "$(RED)ERROR in $(notdir $<)$(NO_COLOR)\n"

end_compile:
	@printf "$(GREEN)Compiling Files: Done$(NO_COLOR)\n"

clean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR) && printf "$(GREEN)Removing minishell object files...$(NO_COLOR)\n"

fclean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@$(RM) $(OBJ_DIR) && printf "$(GREEN)Removing minishell object files...$(NO_COLOR)\n"
	@$(RM) $(NAME) && printf "$(GREEN)Removing minishell binary$(NO_COLOR)\n"
	@printf "$(GREEN)Cleaned up $(NAME)$(NO_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re start_compile end_compile