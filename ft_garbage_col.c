/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:28:52 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/16 09:51:07 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_garbage_col(s_garbage mem)
{
	if (mem->extern_ptr != NULL && mem->allocated_mem != NULL)
	{
		ft_free(mem->allocated_mem);
		mem->extern_ptr == NULL;
	}
	else if (mem->extern_ptr != mem->allocated_mem
		&& mem->allocated_mem != NULL)
	{
		ft_free(mem->allocated_mem);
	}
	else if (mem->extern_ptr == NULL)
	{
		mem->allocated = NULL;
	}
}

/* -------------------------------------------------------------------------- */
/*                                    CASES                                   */
/* -------------------------------------------------------------------------- */
/*
Both internal and external pointer are original / correct
	- free and NULL everything

External points somewhere else. MEM still exists.
	- free ONLY internal PTR (+NULL it), free MEM

External PTR has been nulled (and MEM should have been freed)
	- NULL internal PTR
*/