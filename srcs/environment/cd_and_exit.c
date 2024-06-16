/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_and_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:51:29 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/16 18:00:09 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cd(t_program *shell, char *path)
{
	int	ret;

	ret = chdir(path);
	if (ret == -1)
		printf("minishell: cd: %s: %s\n", path, strerror(errno));
	else
		change_value_both(shell->env, shell->expo, "PWD", getcwd(NULL, 0));
}

void	ms_exit(t_program *shell)
{
	ft_lstclear(&(shell->mem), free);
	rl_clear_history();
	exit(shell->ex_status);
}
