/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:10:56 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/29 15:24:33 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// DISCUSS with partner how to route here, + get path
// either pass it in or have a full path lookup function
// that gets called here

// ToDo: 	replace error func
// 			add path to execve
//			get envp
//			-> getter func?
//			check if safety wrappers break anything

void	execute_cmd(t_cmd *cmd)
{
	if (cmd->type == EXEC)
		exec_exec(cmd);
	else if (cmd->type == REDIR)
		exec_redir(cmd);
	else if (cmd->type == LIST)
		exec_list(cmd);
	else if (cmd->type == PIPE)
		exec_pipe(cmd);
	else if (cmd->type == BACK)
		exec_back(cmd);
	// ft_debug_msg("execute_cmd is exiting the shell");
	// exit(100); // are we already in a subprocess? if yes exit
	// otherwise no. FIX!!!!
}

//  ONLY COMMENTED OUT IN ORDER TO COMPILE TO DEBUG OTHER STUFF!!!
void	exec_exec(t_cmd *cmd)
{
	t_exec_cmd	*exec_cmd;

	exec_cmd = (t_exec_cmd *)cmd;
	if (exec_cmd->argv[0] == 0) // maybe switch to conditional exit if child
		ft_panic("Wrong routing / similar error during exec", 99);
	expand(exec_cmd); // EXPAND HERE
	if (is_builtin(exec_cmd))
	{
		exec_builtin(cmd);
		return ;
	}
	else
		execve(get_path(exec_cmd->argv[0]), exec_cmd->argv, NULL);
	printf("Executing %s failed\n", get_path(exec_cmd->argv[0]));
}

// /// @brief Checks if command is a builtin and executes it.
// /// @param exec_cmd cmd table
// /// @return 1 on is_builtin true
// ///			0 on is_builtin false
// int	is_builtin(t_exec_cmd *exec_cmd)
// {
// 	if (ft_strcmp(exec_cmd, "cmd"))
// 	{
// 		/* code */
// 	}

// }

void	exec_redir(t_cmd *cmd)
{
	t_redir_cmd	*exec_redir;

	exec_redir = (t_redir_cmd *)cmd;
	close(exec_redir->fd);
	if (open(exec_redir->file, exec_redir->mode) < 0)
		ft_panic("opening the file failed.\n", 2);
	execute_cmd(exec_redir->cmd);
}

void	exec_list(t_cmd *cmd)
{
	t_list_cmd	*exec_list;
	pid_t		pid;
	int			status;

	exec_list = (t_list_cmd *)cmd;
	pid = safe_fork();
	if (pid == 0)
		execute_cmd(exec_list->left);
	waitpid(pid, &status, 0);
	execute_cmd(exec_list->right);
}

void	exec_back(t_cmd *cmd)
{
	t_back_cmd	*exec_back;

	exec_back = (t_back_cmd *)cmd;
	if (safe_fork() == 0)
	{
		execute_cmd(exec_back->cmd);
	}
}
