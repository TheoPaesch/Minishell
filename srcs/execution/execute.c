/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:10:56 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/31 19:50:46 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_cmd(t_cmd *cmd)
{
	set_exec_signal();
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
	set_normal_signal();
}

void	exec_exec(t_cmd *cmd)
{
	t_exec_cmd	*exec_cmd;
	pid_t		pid;
	int			status;
	char		*tmp;

	exec_cmd = (t_exec_cmd *)cmd;
	if (exec_cmd->argv[0] && is_builtin(exec_cmd))
		return (exec_builtin(cmd));
	pid = safe_fork();
	if (pid == 0)
	{
		tmp = get_path(exec_cmd->argv[0]);
		if (tmp)
			execve(tmp, exec_cmd->argv, NULL);
		get_shell()->last_exit_code = 127;
		ft_putstr_fd(ft_strjoin("bash: ", exec_cmd->argv[0]), 2);
		ft_putstr_fd(": no such file or directory\n", 2);
		ms_exit(get_shell()->last_exit_code);
	}
	waitpid(pid, &status, 0);
	set_exit_code(WEXITSTATUS(status));
	if ((get_shell())->isatty == false)
		ms_exit((get_shell())->last_exit_code);
}

void	exec_redir(t_cmd *cmd)
{
	t_redir_cmd	*exec_redir;

	exec_redir = (t_redir_cmd *)cmd;
	close(exec_redir->fd);
	if (open(exec_redir->file, exec_redir->mode, 0644) < 0)
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
