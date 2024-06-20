NAME 	= 	minishell

LIBFT_DIR =	./includes/libft
LIBFT	=	./obj/libft/libft.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
RM		=	rm -rf

LIB		=	-lreadline -L$(LIBFT_DIR)
INC		=	-I includes

SRC_DIRS =	./srcs \
			./srcs/environment \
			./srcs/main \
			./srcs/prompt \
			./srcs/signal \
			./srcs/parsing \
			./srcs/tokenizer \
			./srcs/execution


vpath %.c $(SRC_DIRS)
vpath %.h includes

SRC = env_export_execution.c \
      cd_and_exit.c \
      unset.c \
      path_exec.c \
      get_env.c \
      main.c \
      splash.c \
      signal.c \
      prompt.c \
	  constructors.c \
	  nullterm.c \
	  nullterm_utils.c \
	  parse_utils.c \
	  parse_utils_2.c \
	  scan_skip_ws.c \
	  execute.c \
	  safe_utils.c \
	  get_token.c

HEADERS = minishell.h


OBJ_DIR = obj
OBJ 	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# COLORS
BLUE = \033[0;34m
YELLOW = \033[0;33m
GREEN = \033[0;32m
NO_COLOR = \033[0m

all: $(NAME) 

start_compile:
	@printf "$(BLUE)Compiling Minishell...$(NO_COLOR)\n"

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@ $(LIB)
	@printf "$(GREEN)SUCCESS - $(NAME) has been successfully compiled$(NO_COLOR)\n"
	@printf "$(GREEN)Compiling Files: Done$(NO_COLOR)\n"

$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	@printf "$(GREEN)Compiled $(notdir $<)$(NO_COLOR)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR) && printf "$(YELLOW)Removing minishell object files...$(NO_COLOR)\n"

fclean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@$(RM) $(OBJ_DIR) && printf "$(YELLOW)Removing minishell object files...$(NO_COLOR)\n"
	@$(RM) $(NAME) && printf "$(YELLOW)Removing minishell binary$(NO_COLOR)\n"
	@printf "$(GREEN)Cleaned up $(NAME)$(NO_COLOR)\n"

re: fclean all

debug: CFLAGS += -g -fsanitize=address,leak
debug: re

test:
	bash 42_minishell_tester/tester.sh m

# debug: CFLAGS += -fsanitize=address,leak

.PHONY: all test clean fclean re start_compile -DDEBUG=1