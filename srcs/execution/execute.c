/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:10:56 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/27 23:39:01 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	// if ()
	// exit(100); // are we already in a subprocess? if yes exit
	// otherwise no. FIX!!!!
}

void	exec_exec(t_cmd *cmd)
{
	t_exec_cmd	*exec_cmd;
	pid_t		pid;
	int			status;

	exec_cmd = (t_exec_cmd *)cmd;
	if (exec_cmd->argv[0] == 0 /*&& getpid() == 0*/)
		ft_panic("Wrong routing / similar error during exec", 2);
	// add error checking here with argv[0], or in parsing
	if (is_builtin(exec_cmd))
		return (exec_builtin(cmd));
	pid = safe_fork();
	if (pid == 0)
	{
		execve(get_path(exec_cmd->argv[0]), exec_cmd->argv, NULL);
		// printf("errno: %d\n", errno);
		// errno = 127;
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(exec_cmd->argv[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
		ms_exit(errno_to_exitcode(errno));
	}
	waitpid(pid, &status, 0);
	set_exit_code(WEXITSTATUS(status));
	if (!isatty(STDIN_FILENO))
		ms_exit((get_shell())->last_exit_code);
}

void	exec_redir(t_cmd *cmd) // fix for theos early exit
// just add fork b4 redir
{
	t_redir_cmd *exec_redir;

	exec_redir = (t_redir_cmd *)cmd;
	close(exec_redir->fd);
	if (open(exec_redir->file, exec_redir->mode /*, 0777*/) < 0)
		// CONTINUE HERE
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(exec_redir->file, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
		set_exit_code(errno_to_exitcode(errno));
		return ;
	}
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
	set_exit_code(WEXITSTATUS(status));
	execute_cmd(exec_list->right);
}

void	exec_back(t_cmd *cmd)
{
	pid_t		pid;
	int			status;
	t_back_cmd	*exec_back;

	exec_back = (t_back_cmd *)cmd;
	pid = safe_fork();
	if (pid == 0)
		execute_cmd(exec_back->cmd);
	waitpid(pid, &status, 0);
	set_exit_code(WEXITSTATUS(status));
}
