/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:43:04 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/19 16:16:19 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LIBFT.H
#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

/* -------------------------------------------------------------------------- */
/*                                    LIBFT                                   */
/* -------------------------------------------------------------------------- */

/* ----------------------------- STRING HANDLING ---------------------------- */
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int num);
int					ft_isascii(int c);
int					ft_isdigit(int num);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);

/* ------------------------------- LINKED LIST ------------------------------ */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;


t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* --------------------------------- PRINTF --------------------------------- */
int					pf_printf(const char *str, ...);
int					pf_tohexlower(unsigned long n);
int					pf_tohexupper(unsigned long n);
int					pf_utoa(unsigned int n);
int					pf_itoa(int n);
int					pf_putstr(char *s, int fd);
int					pf_putptr(unsigned long int n);

/* ------------------------------ GET NEXT LINE ----------------------------- */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char				*get_next_line(int fd);
void				*gnl_calloc(size_t count, size_t size);
char				*gnl_strdup(char *s1);
char				*gnl_strjoin(char *s1, char *s2);
int					gnl_strlen(const char *s);
int					gnl_strchr(char *s, int c);
// void				gnl_bzero(void *s, size_t n);
size_t				gnl_strlcpy(char *dst, char *src, size_t dstsize);

#endif