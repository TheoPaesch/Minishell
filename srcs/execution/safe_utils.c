/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:01:52 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/30 18:13:12 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Forks the current process, handling errors.
 *
 * Creates a child process. In the child, sets `isatty` to false.
 * Exits if fork fails.
 *
 * @return pid_t PID of the child process, or -1 on failure.
 */
pid_t	safe_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Forking failed.\n");
		exit(1);
	}
	if (pid == 0)
		get_shell()->isatty = false;
	return (pid);
}

/**
 * @brief Creates a pipe, exiting on failure.
 *
 * Initializes a pipe and exits with an error message if pipe creation fails.
 *
 * @param pipefd Array to store read/write file descriptors of the pipe.
 */
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
