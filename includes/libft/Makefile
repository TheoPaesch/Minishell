# NAME, all, clean, fclean, re
# -Wall -Wextra -Werror
# You must use the command ar to create your library. Using the libtool command is forbidden.
# Your libft.a has to be created at the root of your repository.
# If you need helper functions to split a more complex function, define them as static
# functions. This way, their scope will be limited to the appropriate file.

NAME = libft.a

SRCS = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strrchr.c ft_strdup.c\
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_tolower.c ft_toupper.c ft_substr.c\
			ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c\
			ft_striteri.c ft_strmapi.c ft_split.c\
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c\
			ft_lstiter.c ft_lstmap.c\
			pf_printf.c pf_putptr.c pf_tohex.c pf_utoa.c\
			get_next_line_bonus.c get_next_line_utils_bonus.c

OBJECTS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(OBJECTS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJECTS) $(BONUS_OBJS)

.PHONY: clean fclean all re ar bonus