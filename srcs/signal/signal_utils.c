/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:28:43 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/29 21:59:21 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_signal_handler(int signum, void (*handler)(int))
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(signum, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
}

void	handle_sigint(int sig)
{
	(void)sig;
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	heredoc_signal(int sig)
{
	(void)sig;
	g_sig_break = 1;
	rl_done = 1;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	get_shell()->last_exit_code = 1;
}
