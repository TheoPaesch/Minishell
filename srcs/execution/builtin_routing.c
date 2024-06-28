/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_routing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:20:47 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/28 19:26:20 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// @brief Checks if command is a builtin and executes it.
/// @param exec_cmd cmd table
/// @return 1 on is_builtin true
///			0 on is_builtin false
int	is_builtin(t_exec_cmd *exec_cmd)
{
	static const char	*builtins[7] = {"cd", "echo", "env", "export", "exit",
			"pwd", "unset"};
	int					i;

	i = 0;
	while (i <= 6)
	{
		if (ft_strnstr(builtins[i], exec_cmd->argv[0], ft_strlen(builtins[i])))
			return (1);
		i++;
	}
	return (0);
}

void	exec_builtin(t_cmd *cmd)
{
	t_exec_cmd	*exec_cmd;

	// DOES THIS NEED EXIT CODE / STATUS ROUTING / SETTING?
	exec_cmd = (t_exec_cmd *)cmd;
	if (ft_strnstr(exec_cmd->argv[0], "cd", ft_strlen(exec_cmd->argv[0])))
		cd_builtin(cmd);
	if (ft_strnstr(exec_cmd->argv[0], "echo", ft_strlen(exec_cmd->argv[0])))
		echo_builtin(cmd);
	if (ft_strnstr(exec_cmd->argv[0], "env", ft_strlen(exec_cmd->argv[0])))
		env_builtin(cmd);
	if (ft_strnstr(exec_cmd->argv[0], "export", ft_strlen(exec_cmd->argv[0])))
		export_builtin(cmd);
	if (ft_strnstr(exec_cmd->argv[0], "exit", ft_strlen(exec_cmd->argv[0])))
		exit_builtin(cmd);
	if (ft_strnstr(exec_cmd->argv[0], "pwd", ft_strlen(exec_cmd->argv[0])))
		pwd_builtin(cmd);
	if (ft_strnstr(exec_cmd->argv[0], "unset", ft_strlen(exec_cmd->argv[0])))
		unset_builtin(cmd);
	// do exit value handling here?
}
