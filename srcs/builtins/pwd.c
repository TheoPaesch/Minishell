/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:55:53 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/27 18:22:28 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd_builtin(t_cmd *cmd)
{
	char	**args;
	char	*str;

	args = ((t_exec_cmd *)cmd)->argv;
	if (args[1] != NULL)
		return (printf("pwd does not allow options\n"), 1);
	str = getcwd(NULL, 0);
	if (!str)
		return (1);
	printf("%s\n", str);
	free(str);
	return (0);
}


/* just gewtcwd into str then free after*/