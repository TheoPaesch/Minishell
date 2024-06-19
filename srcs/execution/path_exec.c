/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:16:20 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/19 19:02:39 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(char *executable)
{
	int				i;
	char			**folders;
	static t_list	*env_lst;
	t_list			*tmp;

	if (!env_lst)
	{
		env_lst = (t_list *)executable;
		return (NULL);
	}
	i = 0;
	tmp = env_lst;
	while (ft_strcmp(((t_env *)(tmp->data))->key, "PATH"))
		tmp = tmp->next;
	if (tmp == NULL)
		printf("Error: PATH not contained in env\n");
	folders = ft_split(((t_env *)(tmp->data))->value, ':');
	while (folders[i])
	{
		if (access(ft_strjoin(ft_strjoin(folders[i], "/"), executable),
				F_OK | X_OK) == 0)
			return (ft_strjoin(ft_strjoin(folders[i], "/"), executable));
		i++;
	}
	return (printf("Error: command not found\n"), NULL);
}

// Path: srcs/execute/execute.c
// fork before execve
// free split
// save PID from fork for wait untill end and to get exit status
// if pipe is after buildin, fork buildin

// void	path_exec(t_program *shell, char *executable, char **args)
// {
// 	int		i;
// 	char	**folders;

// 	i = 0;
// 	folders = ft_split(((t_env *)shell->env->data)->value, ':');
// 	while (folders[i])
// 	{
// 		if (access(ft_strjoin(ft_strjoin(folders[i], "/"), executable),
// 				F_OK) == 0)
// 		{
// 			execve(ft_strjoin(ft_strjoin(folders[i], "/"), executable), args,
// 				NULL);
// 			break ;
// 		}
// 		i++;
// 	}
// 	while (i > -1)
// 	{
// 		ft_free(folders[i]);
// 		i--;
// 	}
// }
