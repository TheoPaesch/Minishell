/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:10:22 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/30 18:00:50 by mstrauss         ###   ########.fr       */
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
	t_pipe_vars	v;

	v.shell = get_shell();
	v.exec_pipe = (t_pipe_cmd *)cmd;
	safe_pipe(v.pipes);
	v.pid1 = safe_fork();
	exec_pipe_left(v.pid1, &v.pipes, v.exec_pipe);
	v.pid2 = safe_fork();
	exec_pipe_right(v.pid2, &v.pipes, v.exec_pipe);
	close(v.pipes[0]);
	close(v.pipes[1]);
	waitpid(v.pid1, &v.stat_pid1, 0);
	waitpid(v.pid2, &v.stat_pid2, 0);
	if (WIFEXITED(v.stat_pid1))
		v.shell->last_exit_code = WEXITSTATUS(v.stat_pid1);
	if (WIFEXITED(v.stat_pid2))
		v.shell->last_exit_code = WEXITSTATUS(v.stat_pid2);
	if ((get_shell())->isatty == false)
		ms_exit(v.shell->last_exit_code);
}
