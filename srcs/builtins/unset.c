/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:49:17 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/21 20:50:24 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_builtin(t_cmd *cmd)
{
	t_program	*shell;
	char		**keys;
	int			i;

	i = 1;
	shell = get_shell();
	keys = ((t_exec_cmd *)cmd)->argv;
	while (keys[i])
	{
		unset_one(shell->env, shell->expo, *keys);
		i++;
	}
	return (0);
}
