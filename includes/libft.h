/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:43:04 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/15 15:58:58 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LIBFT.H
#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

// ##############################  LINKED LISTS  ##############################
typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

typedef struct s_env
{
	char			*key;
	char			*value;
}					t_env;

t_list				*ft_lstnew(void *content);
void				ft_lstdad_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
#endif