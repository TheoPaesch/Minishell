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
	exit(100); // are we already in a subprocess? if yes exit
				// otherwise no. FIX!!!!
}

//  ONLY COMMENTED OUT IN ORDER TO COMPILE TO DEBUG OTHER STUFF!!!
void	exec_exec(t_cmd *cmd)
{
	t_exec_cmd	*exec_cmd;

	exec_cmd = (t_exec_cmd *)cmd;
	if (exec_cmd->argv[0] == 0)
	{
		perror("Wrong routing / similar error during exec\n");
		exit(1);
	}
	execve(get_path(exec_cmd->argv[0]), exec_cmd->argv, NULL);
	printf("Executing %s failed\n", get_path(exec_cmd->argv[0]));
}

void	exec_redir(t_cmd *cmd)
{
	t_redir_cmd	*exec_redir;

	exec_redir = (t_redir_cmd *)cmd;
	close(exec_redir->fd);
	if (open(exec_redir->file, exec_redir->mode) < 0)
	{
		printf("Opening the %s file failed.\n", exec_redir->file);
		// change to fd2
		exit(1);
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
	execute_cmd(exec_list->right);
}

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
	t_pipe_cmd	*exec_pipe;
	int			pipes[2];
	pid_t		pid1;
	pid_t		pid2;

	exec_pipe = (t_pipe_cmd *)cmd;
	safe_pipe(pipes);
	pid1 = safe_fork();
	exec_pipe_left(pid1, &pipes, exec_pipe);
	pid2 = safe_fork();
	exec_pipe_right(pid2, &pipes, exec_pipe);
	close(pipes[0]);
	close(pipes[1]);
	waitpid(pid1, NULL, 0); // we may need exit status,
	waitpid(pid2, NULL, 0); // change null to status
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
