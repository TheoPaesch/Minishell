/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_routing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:20:47 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/23 13:58:07 by mstrauss         ###   ########.fr       */
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
		if (ft_strnstr(builtins[i], exec_cmd->argv[1], ft_strlen(builtins[i])))
			return (1);
	}
	return (0);
}

void	exec_builtin(t_cmd *cmd)
{
	t_exec_cmd	*exec_cmd;

	exec_cmd = (t_exec_cmd *)cmd;
	if (ft_strnstr(exec_cmd->argv[0], "cd", ft_strlen(exec_cmd->argv[0])))
		cd(get_shell(), exec_cmd->argv[1]);
	if (ft_strnstr(exec_cmd->argv[0], "echo", ft_strlen(exec_cmd->argv[0])))
		ms_echo(cmd);
	if (ft_strnstr(exec_cmd->argv[0], "env", ft_strlen(exec_cmd->argv[0])))
		env(); // fill params
	if (ft_strnstr(exec_cmd->argv[0], "export", ft_strlen(exec_cmd->argv[0])))
		export(); // fill params
	if (ft_strnstr(exec_cmd->argv[0], "exit", ft_strlen(exec_cmd->argv[0])))
		ms_exit(); // fill params
	if (ft_strnstr(exec_cmd->argv[0], "pwd", ft_strlen(exec_cmd->argv[0])))
		pwd(); // fill params
	if (ft_strnstr(exec_cmd->argv[0], "unset", ft_strlen(exec_cmd->argv[0])))
		unset(); // fill params
}
// do exit value handling here?
}
