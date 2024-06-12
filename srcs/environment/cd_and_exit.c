/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_and_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:51:29 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/12 00:14:06 by mstrauss         ###   ########.fr       */
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
	t_list	*tmp;

	tmp = shell->mem;
	while (tmp != NULL)
	{
		((t_mem *)(tmp->data))->ext_ptr = NULL;
		ft_free(((t_mem *)(tmp->data))->allocd_mem);
		ft_free(&(tmp->data));
		// ft_free(&(shell->mem));
		tmp = tmp->next;
	}
	rl_clear_history();
	exit(shell->ex_status);
}