/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:14:46 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/26 17:54:41 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_program	*init_global(t_program *shell)
{
	static t_program	*program = NULL;

	if (program == NULL)
		program = shell;
	return (program);
}

t_program	*get_shell(void)
{
	return (init_global(NULL));
}
