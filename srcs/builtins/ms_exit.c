/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:15:38 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/26 13:19:16 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_exit(t_program *shell)
{
	ft_lstclear(&(shell->mem), free);
	rl_clear_history();
	exit(shell->ex_status);
}

int	exit_builtin(t_cmd *cmd)






// have to implement to check if argument is a number and then use it with modulo 255 to exit the shell with the correct status (exit status is a number between 0 and 255)