/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:07:38 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/24 14:44:40 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_echo(t_cmd *cmd)
{
	t_exec_cmd		*exec_cmd;
	bool			n_flag;
	unsigned int	i;

	exec_cmd = (t_exec_cmd *)cmd;
	n_flag = false;
	i = 0;
	if (ft_strnstr(exec_cmd->argv[0], "echo",
			ft_strlen(exec_cmd->argv[0])) != 0)
		ft_panic("routed to builtin echo, but argv[0] is not '*echo'", 99);
	if (ft_strcmp(exec_cmd->argv[1], "-n"))
	{
		n_flag = true;
		i++;
	}
	while (exec_cmd->argv[i] != NULL)
	{
		ft_putstr_fd(exec_cmd->argv[i], 1);
		i++;
	}
	if (n_flag == true)
		ft_putchar_fd('\n', 1);
	return ;
}

// typedef struct s_exec_cmd
// {
// 	int			type;

// 	char		*argv[MAXARGS];
// 	char		*end_argv[MAXARGS];
// }				t_exec_cmd;
