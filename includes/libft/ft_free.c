/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:07:39 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/12 13:00:39 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free(void *ptr)
{
	if (ptr == NULL )
		return ;
	printf("adress %p was freed\n", ptr);
	free(ptr);
	ptr = NULL;
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
