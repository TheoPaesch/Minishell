/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullterm_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:46:55 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/03 20:14:12 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*null_exec_cmd(t_cmd *cmd)
{
	t_exec_cmd	*exec_cmd;
	int			i;

	i = 0;
	exec_cmd = (t_exec_cmd *)cmd;
	while (exec_cmd->argv[i])
	{
		*exec_cmd->end_argv[i] = 0;
		i++;
	}
	return (cmd);
}

t_cmd	*null_redir(t_cmd *cmd)
{
	nullterm(((t_redir_cmd *)cmd)->cmd);
	((t_redir_cmd *)cmd)->end_file = 0;
	return (cmd);
}

t_cmd	*null_pipe(t_cmd *cmd)
{
	nullterm(((t_pipe_cmd *)cmd)->left);
	nullterm(((t_pipe_cmd *)cmd)->right);
	return (cmd);
}

t_cmd	*null_list(t_cmd *cmd)
{
	nullterm(((t_list_cmd *)cmd)->left);
	nullterm(((t_list_cmd *)cmd)->right);
	return (cmd);
}

t_cmd	*null_back(t_cmd *cmd)
{
	nullterm(((t_back_cmd *)cmd)->cmd);
	return (cmd);
}
