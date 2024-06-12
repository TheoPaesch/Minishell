#include "../../includes/minishell.h"

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
	execve("placeholder path\n", exec_cmd->argv, envp);
	// change once PATHfunc exists
	printf("Executing %s failed\n", "placeholder path");
	// change once PATHfunc exist
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

void	exec_pipe(t_cmd *cmd)
{
	t_pipe_cmd	*exec_pipe;
	int			pipes[2];
	pid_t		pid1;
	pid_t		pid2;

	exec_pipe = (t_pipe_cmd *)cmd;
	safe_pipe(pipes);
	pid1 = safe_fork();
	if (pid1 == 0)
	{
		close(1);
		dup(pipes[1]);
		close(pipes[0]);
		close(pipes[1]);
		execute_cmd(exec_pipe->left);
	}
	pid2 = safe_fork();
	if (pid2 == 0)
	{
		close(0);
		dup(pipes[0]);
		close(pipes[0]);
		close(pipes[1]);
		execute_cmd(exec_pipe->right);
		exit(0);
	}
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
