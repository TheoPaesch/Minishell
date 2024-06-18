/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:43:04 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/15 02:21:54 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LIBFT.H
#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* -------------------------------------------------------------------------- */
/*                                    LIBFT                                   */
/* -------------------------------------------------------------------------- */
typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

// typedef struct s_mem
// {
// 	void			**ext_ptr;
// 	void			*allocd_mem;
// }					t_mem;

/* ----------------------------- STRING HANDLING ---------------------------- */
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_free(void *ptr);
void				*ft_memnew(void *data);
void				remove_mem_entry(t_list **lst, void *ptr);
int					ft_isalnum(int c);
int					ft_isalpha(int num);
int					ft_isascii(int c);
int					ft_isdigit(int num);
int					ft_isprint(int c);
void				*ft_malloc(size_t size);
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
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strjoinall(int count, bool free, ...);
size_t				ft_strcspn(const char *str1, const char *str2);
size_t				ft_strspn(const char *str1, const char *str2);

/* ------------------------------- LINKED LIST ------------------------------ */

t_list				*ft_lstnew(void *data);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
// void				ft_del_mem(t_mem *mem);

/* --------------------------------- PRINTF --------------------------------- */
// int					pf_printf(const char *str, ...);
// int					pf_tohexlower(unsigned long n);
// int					pf_tohexupper(unsigned long n);
// int					pf_utoa(unsigned int n);
// int					pf_itoa(int n);
// int					pf_putstr(char *s, int fd);
// int					pf_putptr(unsigned long int n);

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