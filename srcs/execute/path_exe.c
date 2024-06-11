/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:16:20 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/10 15:54:22 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	path_exe(t_program *shell, char *executable, char **args)
{
	int		i;
	char	**folders;

	i = 0;
	folders = ft_split(((t_env *)shell->env->content)->value, ':');
	while (folders[i])
	{
		if (access(ft_strjoin(ft_strjoin(folders[i], "/"), executable),
				F_OK) == 0)
		{
			execve(ft_strjoin(ft_strjoin(folders[i], "/"), executable), args,
				NULL);
			break ;
		}
		i++;
	}
    while (i > -1)
    {
        ft_free(folders[i]);
        i--;
    }
}

// Path: srcs/execute/execute.c
// fork before execve
// free split
// save PID from fork for wait untill end and to get exit status
// if pipe is after buildin, fork buildin