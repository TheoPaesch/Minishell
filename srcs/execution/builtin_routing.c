/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_routing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:20:47 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/30 17:33:02 by mstrauss         ###   ########.fr       */
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
	char				*lower_str;

	i = -1;
	lower_str = exec_cmd->argv[0];
	i = 0;
	while (i <= 6)
	{
		if (!ft_strcmp(builtins[i], lower_str))
			return (1);
		i++;
	}
	return (0);
}

void	exec_builtin(t_cmd *cmd)
{
	t_exec_cmd	*exec_cmd;
	t_program	*shell;

	shell = get_shell();
	exec_cmd = (t_exec_cmd *)cmd;
	if (ft_strnstr(exec_cmd->argv[0], "cd", ft_strlen(exec_cmd->argv[0])))
		shell->last_exit_code = cd_builtin(cmd);
	if (ft_strnstr(exec_cmd->argv[0], "echo", ft_strlen(exec_cmd->argv[0])))
		shell->last_exit_code = echo_builtin(cmd);
	if (ft_strnstr(exec_cmd->argv[0], "env", ft_strlen(exec_cmd->argv[0])))
		shell->last_exit_code = env_builtin(cmd);
	if (ft_strnstr(exec_cmd->argv[0], "export", ft_strlen(exec_cmd->argv[0])))
		shell->last_exit_code = export_builtin(cmd);
	if (ft_strnstr(exec_cmd->argv[0], "exit", ft_strlen(exec_cmd->argv[0])))
		shell->last_exit_code = exit_builtin(cmd);
	if (ft_strnstr(exec_cmd->argv[0], "pwd", ft_strlen(exec_cmd->argv[0])))
		shell->last_exit_code = pwd_builtin(cmd);
	if (ft_strnstr(exec_cmd->argv[0], "unset", ft_strlen(exec_cmd->argv[0])))
		shell->last_exit_code = unset_builtin(cmd);
}
