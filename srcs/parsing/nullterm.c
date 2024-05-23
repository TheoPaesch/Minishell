/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullterm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:34:29 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/19 13:49:56 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/// @brief Identifies the type of cmd passed and null terminates their strings
/// @return pointer to the command struct
struct cmd	*nullterm(struct s_cmd *cmd)
{
	if (cmd == NULL)
		return (NULL);
	if (cmd->type == EXEC)
		null_exec_cmd(cmd);
	else if (cmd->type == REDIR)
		null_redir(cmd);
	else if (cmd->type == PIPE)
		null_pipe(cmd);
	else if (cmd->type == LIST)
		null_list(cmd);
	else if (cmd->type == BACK)
		null_back(cmd);
	return (cmd);
}
