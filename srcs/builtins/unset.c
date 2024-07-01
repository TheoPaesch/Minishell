/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:49:17 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/01 15:08:02 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
@tpaesch
segfaults in utils, during stuff like this:
if	(ft_strcmp(((t_env *)env->next->data)->key, key) == 0)
because
doesnt check if next exists
doesnt check if data exists
doesnt check if key exists

I dont understand what prepointer is, please clarify to me if possible.
If it only remembers the previous node, just do that in the actual function pls
t_list	*prev;
*/

int	unset_builtin(t_cmd *cmd)
{
	t_program	*shell;
	char		**keys;
	int			i;

	i = 1;
	shell = get_shell();
	keys = ((t_exec_cmd *)cmd)->argv;
	while (keys[i])
	{
		unset_one(shell->env, shell->expo, *keys);
		i++;
	}
	return (0);
}
