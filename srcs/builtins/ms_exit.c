/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:15:38 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/27 16:45:52 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_exit(t_program *shell)
{
	ft_lstclear(&(shell->mem), free);
	rl_clear_history();
	exit(shell->ex_status);
}

void	exit_builtin(t_cmd *cmd)
{
	t_program	*shell;
	char		**args;
	int			tmp;

	shell = get_shell();
	args = ((t_exec_cmd *)cmd)->argv;
	if (args != NULL)
	{
		tmp = atoi(args[1]);
		tmp = tmp % 255;
		shell->ex_status = tmp;
	}
	ms_exit(shell);
}
