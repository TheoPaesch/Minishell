/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:57:53 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/10 16:30:32 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
BOILERPLATE FOR CONSTRUCTORS

t_cmd	*_cmd(void)
{
	t__cmd	*cmd;

	ft_malloc(cmd, sizeof(*cmd));
	ft_memset(cmd, 0, sizeof(*cmd));
	return ((t_cmd *)cmd);
}
*/

t_cmd	*exec_cmd(void)
{
	t_exec_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	cmd->type = EXEC;
	return ((t_cmd *)cmd);
}

t_cmd	*redir_cmd(t_cmd *sub_cmd, char *file, char *end_file, int mode)
{
	t_redir_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	cmd->type = REDIR;
	cmd->cmd = sub_cmd;
	cmd->file = file;
	cmd->end_file = end_file;
	cmd->mode = mode;
	// cmd->fd = fd;	// handled outside of this func for NORM *4param max)
	return ((t_cmd *)cmd);
}

t_cmd	*pipe_cmd(t_cmd *left, t_cmd *right)
{
	t_pipe_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	cmd->type = PIPE;
	cmd->left = left;
	cmd->right = right;
	return ((t_cmd *)cmd);
}

t_cmd	*list_cmd(t_cmd *left, t_cmd *right)
{
	t_list_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	cmd->type = LIST;
	cmd->left = left;
	cmd->right = right;
	return ((t_cmd *)cmd);
}

t_cmd	*back_cmd(t_cmd *sub_cmd)
{
	t_back_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	cmd->type = BACK;
	cmd->cmd = sub_cmd;
	return ((t_cmd *)cmd);
}
