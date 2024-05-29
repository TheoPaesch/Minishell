/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:37:49 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/29 16:10:05 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_malloc(void *ptr, size_t size)
{
	static t_list	**allocs;
	t_mem			*mem;
	void			**ext_ptr;

	if (allocs == NULL && size == 0)
		return (allocs = ptr, 2);
	ext_ptr = (void **)ptr;
	if (ext_ptr == NULL)
		return (printf("Error: called malloc with a wrong param\n"), 0);
	else
	{
		mem = malloc(sizeof(t_mem));
		if (!mem)
		{
			printf("Malloc failed\n");
			exit(1);
		}
		*ext_ptr = malloc(size);
		mem->allocd_mem = *ext_ptr;
		mem->ext_ptr = ext_ptr;
		ft_lstadd_front(allocs, ft_lstnew(mem));
	}
	return (1);
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