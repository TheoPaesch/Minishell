/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:37:49 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/21 22:45:26 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_malloc(void *ptr, size_t size)
{
	static t_list	*allocs;
	void			**ext_ptr;

	ext_ptr = (void **)ptr;
	*ext_ptr = malloc(size);
	if (*ext_ptr == NULL)
		return (1);
	if (!allocs)
		allocs = ft_lstnew(*ext_ptr);
	else
		ft_lstadd_front(&allocs, ft_lstnew(*ext_ptr));
	return (0);
}

int	main(void)
{
	char	*str;

	ft_malloc(&str, 2);
	return (0);
}

/* -------------------------------------------------------------------------- */
/*                                 EXPLANATION                                */
/* -------------------------------------------------------------------------- */
/*

// the pointer that we create in malloc() in order to remember where we allocted
void		*allocated_mem; // internal to malloc()/garbage_collection

typedef struct s_garbage
{
	void			**extern_ptr;  //the ptr/var used in our main thread/program
	void			*allocated_mem;//the actual location of allocated memory
}					t_garbage;



typedef struct s_list
{
	void			*data; // store s_garbage here
	struct s_list	*next;
}					t_list;
*/