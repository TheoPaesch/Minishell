/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:16:20 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/31 18:28:12 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path(char *executable)
{
	static t_list	**env_lst;
	t_list			*tmp;
	int				i;
	char			**folders;
	char			*rtrn;

	if (!env_lst)
		return (env_lst = (t_list **)executable, NULL);
	if (*executable == '/' || *executable == '.')
		return (executable);
	i = 0;
	tmp = *env_lst;
	while (tmp && tmp->data != NULL
		&& ft_strcmp(((t_env *)(tmp->data))->key, "PATH"))
		tmp = tmp->next;
	if (tmp == NULL)
		return (NULL);
	folders = ft_split(((t_env *)(tmp->data))->value, ':');
	while (folders[i])
	{
		rtrn = ft_strjoin(ft_strjoin(folders[i++], "/"), executable);
		if (access(rtrn, F_OK | X_OK) == 0)
			return (rtrn);
	}
	return (path_cwd_fallback(executable));
}

char	*path_cwd_fallback(char *executable)
{
	char	*cwd_exe;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	cwd_exe = ft_strjoin(cwd, executable);
	if (access(cwd_exe, F_OK | X_OK) == 0)
		return (free(cwd), cwd_exe);
	return (NULL);
}
