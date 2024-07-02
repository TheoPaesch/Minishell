#include "minishell.h"

pid_t	safe_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Forking failed.\n");
		exit(1);
	}
	return (pid);
}

void	safe_pipe(int pipefd[2])
{
	int	status;

	status = pipe(pipefd);
	if (status < 0)
	{
		perror("Creating pipe failed.\n");
		exit(1);
	}
}
