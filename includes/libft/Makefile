##########################################
#                                        #
#   ██╗     ██╗██████╗ ███████╗████████╗ #
#   ██║     ██║██╔══██╗██╔════╝╚══██╔══╝ #
#   ██║     ██║██████╔╝█████╗     ██║    #
#   ██║     ██║██╔══██╗██╔══╝     ██║    #
#   ███████╗██║██████╔╝██║        ██║    #
#   ╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝    #
##########################################

NAME = libft.a
OBJ_DIR = ../../obj/libft/

SRC_DIRS = includes/ \
			includes/libft/

vpath %.c $(SRC_DIRS)

SRCS =  ft_atoi.c ft_calloc.c ft_isalnum.c \
        ft_isalpha.c ft_isascii.c ft_isdigit.c \
        ft_isprint.c ft_bzero.c ft_memchr.c \
        ft_memcmp.c ft_memcpy.c ft_memmove.c \
        ft_memset.c ft_strchr.c ft_strrchr.c \
        ft_strdup.c ft_strlcat.c ft_strlcpy.c \
        ft_strlen.c ft_strncmp.c ft_strnstr.c \
        ft_tolower.c ft_toupper.c ft_substr.c \
        ft_strjoin.c ft_strtrim.c ft_putchar_fd.c \
        ft_putstr_fd.c ft_putendl_fd.c ft_itoa.c \
        ft_striteri.c ft_strmapi.c ft_split.c \
        ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
        ft_lstadd_back.c ft_lstlast.c ft_lstdelone.c \
        ft_lstclear.c ft_lstiter.c ft_lstmap.c \
        ft_free.c ft_malloc.c \
        get_next_line_bonus.c get_next_line_utils_bonus.c \
        ft_strcspn.c ft_strspn.c ft_strcmp.c \
		ft_debug_msg.c ft_panic.c \
        ft_strjoinall.c ft_strcpy.c

OBJECTS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g #-Ofast -ffast-math -march=native -mtune=native -funroll-loops # -fsanitize=address -fsanitize=undefined

# COLORS
BLUE = \033[0;34m
YELLOW = \033[0;33m
GREEN = \033[0;32m
NO_COLOR = \033[0m

all: start_compile $(OBJ_DIR)$(NAME)

start_compile:
	@mkdir -p $(OBJ_DIR)
	@printf "$(BLUE)Compiling Libft... $(NO_COLOR)\n"
	@printf "$(BLUE)Compiler: $(CC)$(NO_COLOR)\n"
	@printf "$(BLUE)C-Flags: $(CFLAGS)$(NO_COLOR)\n\n"

$(OBJ_DIR)$(NAME): $(OBJECTS)
	@ar -rcs $(OBJ_DIR)$(NAME) $(OBJECTS)
	@printf "\n$(GREEN)SUCCESS - libft.a has been successfully compiled$(NO_COLOR)\n\n"

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN)Compiled $<$(NO_COLOR)\n"

debug: CFLAGS += -fsanitize=address -fsanitize=undefined -DDEBUG=true
debug: re

clean:
	@rm -rf $(OBJ_DIR) && printf "$(GREEN)Removing libft object files...$(NO_COLOR)\n"

fclean: clean
	@rm -f $(OBJ_DIR)$(NAME) && printf "$(GREEN)Removing libft.a$(NO_COLOR)\n"

re: fclean all

# debug: CFLAGS += -fsanitize=address,leak

.PHONY: clean fclean all re start_compile end_compile debug