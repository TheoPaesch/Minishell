/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:37:49 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/11 23:14:52 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	*ft_memnew(void *data)
{
	t_list	*sl1;

	sl1 = malloc(sizeof(t_list));
	if (sl1 == NULL)
		exit(1);
	sl1->data = data;
	sl1->next = NULL;
	return (sl1);
}

int	ft_malloc(void *ptr, size_t size)
{
	static t_list	**allocs;
	t_mem			*mem;
	void			**ext_ptr;

	if (allocs == NULL && size == 0)
		return (allocs = ptr, 2);
	ext_ptr = (void **)ptr;
	if (ext_ptr == NULL)
		return (printf("Error: called malloc with a wrong param.\n"), 0);
	else
	{
		mem = malloc(sizeof(t_mem));
		if (!mem)
		{
			printf("Malloc failed.\n");
			exit(1);
		}
		*ext_ptr = malloc(size);
		mem->allocd_mem = *ext_ptr;
		mem->ext_ptr = ext_ptr;
		ft_lstadd_front(allocs, ft_memnew(mem));
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