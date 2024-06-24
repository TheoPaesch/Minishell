/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_routing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:20:47 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/24 14:03:39 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// @brief Checks if command is a builtin and executes it.
/// @param exec_cmd cmd table
/// @return 1 on is_builtin true
///			0 on is_builtin false
int	is_builtin(t_exec_cmd *exec_cmd)
{
	const static char	*builtins[7] = {"cd", "echo", "env", "export", "exit",
			"pwd", "unset"};
	int					i;

	i = 0;
	while (i <= 6)
	{
		if (ft_strcmp(builtins[i], exec_cmd->argv[1]))
			return (1);
	}
	return (0);
}

void	exec_builtin(t_cmd *cmd)
{
	t_exec_cmd	*exec_cmd;

	exec_cmd = (t_exec_cmd *)cmd;
}
