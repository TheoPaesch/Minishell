/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:49:17 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/26 13:11:39 by tpaesch          ###   ########.fr       */
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
