/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:37:49 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/15 02:23:59 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_memnew(void *data)
{
	t_list	*sl1;

	sl1 = malloc(sizeof(t_list));
	if (sl1 == NULL)
		exit(1);
	sl1->data = data;
	sl1->next = NULL;
	return (sl1);
}

t_list	**init_mem_man(t_list **shell_mem)
{
	static t_list	**allocs = NULL;

	if (allocs == NULL)
		allocs = shell_mem;
	return (allocs);
}

t_list	**get_mem_lst(void)
{
	return (init_mem_man(NULL));
}

void	*ft_malloc(size_t size)
{
	void			*mem;
	static t_list	**allocs = NULL;

	if (allocs == NULL && size == 0)
	{
		mem = malloc(sizeof(t_list));
		return (mem);
	}
	else if (allocs == NULL)
	{
		allocs = get_mem_lst();
		return (NULL);
	}
	mem = malloc(size);
	if (!mem)
	{
		printf("Malloc failed.\n");
		exit(-1);
	}
	ft_lstadd_front(allocs, ft_memnew(mem));
	return (mem);
}

/* -------------------------------------------------------------------------- */
/*                                 EXPLANATION                                */
/* -------------------------------------------------------------------------- */
/*

	! gets called like a normal malloc with a normal return of address !

	-	stores the address of any allocated memory in a linked list (allocs)

typedef struct s_list
{
	void			*data; // store address of allocated memory here
	struct s_list	*next; // -> set by ft_lstadd_front
}		t_list;
*/