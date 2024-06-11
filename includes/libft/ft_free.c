/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:07:39 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/11 23:14:35 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free(void *ptr)
{
	void	**tmp;
	void	**tmp;

	tmp = (void **)ptr;
	tmp = (void **)ptr;
	if (tmp == NULL || *tmp == NULL)
		return ;
	free(ptr);
	*tmp = NULL;
}

/* -------------------------------------------------------------------------- */
/*                                 EXPLANATION                                */
/* -------------------------------------------------------------------------- */
/*

malloc takes the PTR as an argument.
	it allocates the requested memory.
	it remembers which memory it allocated by writing its address to s_garbage
		in a list.
	it remembers the pointer it assigned the allocated memory to (in s_garbage)

No matter how freeing is done (manual first, then garbage collection / reverse)
there will be no double frees due to all pointers being set to NULL afterfreein


EXAMPLE:
int	main(void)
{
	void	*extern_ptr;

	ft_malloc(size, &extern_ptr);
	if (!extern_ptr)				// malloc fail checks still possible
		error();
	ft_free(&extern_ptr);			// normal freeing still possible
}
*/
