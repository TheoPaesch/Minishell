/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:57:53 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/02 19:58:46 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* ---------------------- BOILERPLATE FOR CONSTRUCTORS ---------------------- */
/*
t_cmd	*_cmd(void)
{
	t__cmd	*cmd;

	ft_malloc(cmd, sizeof(*cmd));
	ft_memset(cmd, 0, sizeof(*cmd));
	return ((t_cmd *)cmd);
}
*/

t_cmd	*init_exec_cmd(void)
{
	t_exec_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	cmd->type = EXEC;
	return ((t_cmd *)cmd);
}

/*
				Always set { cmd->fd = fd } outside of this function.
!!ATTENTION!!	Adding another parameter wouldn't have complied with
				the NORMs max_param = 4 rule.
*/
t_cmd	*init_redir_cmd(t_cmd *sub_cmd, char *file, char *end_file, int mode)
{
	t_redir_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	cmd->type = REDIR;
	cmd->cmd = sub_cmd;
	cmd->file = file;
	cmd->end_file = end_file;
	cmd->mode = mode;
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

t_cmd	*init_back_cmd(t_cmd *sub_cmd)
{
	t_back_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(*cmd));
	cmd->type = BACK;
	cmd->cmd = sub_cmd;
	return ((t_cmd *)cmd);
}
