/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullterm_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:46:55 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/19 14:54:40 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

struct cmd	*null_exec_cmd(struct cmd *cmd)
{
	struct s_exec_cmd	*exec_cmd;
	int					i;

	i = 0;
	exec_cmd = (struct s_exec_cmd *)cmd;
	while (exec_cmd->argv[i])
		*exec_cmd->end_argv[i] = 0;
	return (cmd);
}

struct cmd	*null_redir(struct cmd *cmd)
{
	struct s_redir_cmd	*redir_cmd;
	int					i;

	i = 0;
	redir_cmd = (struct s_redir_cmd *)cmd;
	nullterm(redir_cmd->cmd);
	redir_cmd->efile = 0;
	return (cmd);
}

struct cmd	*null_pipe(struct s_pipe_cmd *cmd)
{
	int					i;
	struct s_pipe_cmd	*pipe_cmd;

	i = 0;
	pipe_cmd = cmd;
	nullterm(pipe_cmd->left);
	nullterm(pipe_cmd->right);
	return (cmd);
}

struct cmd	*null_list(struct cmd *cmd)
{
	int					i;
	struct s_list_cmd	*list_cmd;

	i = 0;
	list_cmd = (struct s_list_cmd *)cmd;
	nullterm(list_cmd->left);
	nullterm(list_cmd->right);
	return (cmd);
}

struct cmd	*null_back(struct cmd *cmd)
{
	struct s_back_cmd	*back_cmd;
	int					i;

	i = 0;
	back_cmd = (struct s_back_cmd *)cmd;
	nullterm(back_cmd->cmd);
	return (cmd);
}
