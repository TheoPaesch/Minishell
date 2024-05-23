/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:57:53 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/20 16:38:21 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
BOILERPLATE FOR CONSTRUCTORS

struct cmd	*_cmd(void)
{
	struct s__cmd	*cmd;

	ft_malloc(cmd, sizeof(*cmd));
	ft_memset(cmd, 0, sizeof(*cmd));
	return ((struct cmd *)cmd);
}
*/

struct s_cmd	*exec_cmd(void)
{
	struct s_exec_cmd	*cmd;

	ft_calloc(cmd, sizeof(*cmd));
	cmd->type = EXEC;
	return ((struct cmd *)cmd);
}

struct s_cmd	*redir_cmd(struct s_cmd *sub_cmd, char *file, char *end_file,
		int mode, int fd)
{
	struct s_redir_cmd	*cmd;

	ft_calloc(cmd, sizeof(*cmd));
	cmd->type = REDIR;
	cmd->cmd = sub_cmd;
	cmd->file = file;
	cmd->end_file = end_file;
	cmd->mode = mode;
	cmd->fd = fd;
	return ((struct cmd *)cmd);
}

struct s_cmd	*pipe_cmd(struct s_cmd *left, struct s_cmd *right)
{
	struct s_pipe_cmd	*cmd;

	ft_calloc(cmd, sizeof(*cmd));
	cmd->type = PIPE;
	cmd->left = left;
	cmd->right = right;
	return ((struct cmd *)cmd);
}

struct s_cmd	*list_cmd(struct s_cmd *left, struct s_cmd *right)
{
	struct s_pipe_cmd	*cmd;

	ft_calloc(cmd, sizeof(*cmd));
	cmd->type = LIST;
	cmd->left = left;
	cmd->right = right;
	return ((struct cmd *)cmd);
}

struct s_cmd	*back_cmd(struct cmd *subcmd)
{
	struct s_back_cmd	*cmd;

	ft_calloc(cmd, sizeof(*cmd));
	cmd->type = BACK;
	cmd->cmd = subcmd;
	return ((struct cmd *)cmd);
}
