/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:10:22 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/16 17:03:50 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

inline void	exec_pipe_left(pid_t pid, int (*pipes)[2], t_pipe_cmd *p_cmd)
{
	if (pid == 0)
	{
		dup2((*pipes)[1], 1);
		close((*pipes)[0]);
		close((*pipes)[1]);
		execute_cmd(p_cmd->left);
		exit(0);
	}
}

inline void	exec_pipe_right(pid_t pid, int (*pipes)[2], t_pipe_cmd *p_cmd)
{
	if (pid == 0)
	{
		close(0);
		dup2((*pipes)[0], 0);
		close((*pipes)[0]);
		close((*pipes)[1]);
		execute_cmd(p_cmd->right);
		exit(0);
	}
}

void	exec_pipe(t_cmd *cmd)
{
	t_program	*shell;
	t_pipe_cmd	*exec_pipe;
	int			pipes[2];
	pid_t		pid1;
	pid_t		pid2;
	int			stat_pid1;
	int			stat_pid2;

	shell = get_shell();
	exec_pipe = (t_pipe_cmd *)cmd;
	safe_pipe(pipes);
	pid1 = safe_fork();
	exec_pipe_left(pid1, &pipes, exec_pipe);
	pid2 = safe_fork();
	exec_pipe_right(pid2, &pipes, exec_pipe);
	close(pipes[0]);
	close(pipes[1]);
	waitpid(pid1, &stat_pid1, 0); // WNOHANG |
	waitpid(pid2, &stat_pid1, 0);
	if (WIFEXITED(stat_pid1))
		shell->ex_status = WEXITSTATUS(stat_pid1);
	else
		shell->ex_status = 128 + WTERMSIG(stat_pid2);
}
