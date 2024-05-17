/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:28:52 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/17 15:47:45 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_del_mem(t_mem *mem)
{
	if (mem->ext_ptr != NULL && mem->allocd_mem != NULL)
	{
		ft_free(mem->allocd_mem);
		mem->ext_ptr = NULL;
	}
	else if (mem->ext_ptr != mem->allocd_mem && mem->allocd_mem != NULL)
	{
		ft_free(mem->allocd_mem);
	}
	else if (mem->ext_ptr == NULL)
	{
		mem->allocd_mem = NULL;
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