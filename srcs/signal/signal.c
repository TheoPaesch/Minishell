/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:29:08 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/31 12:45:56 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_heredoc_signal(void)
{
	set_signal_handler(SIGINT, heredoc_signal);
	set_signal_handler(SIGQUIT, SIG_IGN);
}

void	set_normal_signal(void)
{
	set_signal_handler(SIGINT, handle_sigint);
	set_signal_handler(SIGQUIT, SIG_IGN);
	g_sig_break = 0;
}

void	signals_init(void)
{
	rl_catch_signals = 0;
	set_normal_signal();
}

void	set_exec_signal(void)
{
	signal(SIGINT, exec_signal);
	signal(SIGQUIT, exec_signal);
}
