/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:51:29 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/28 18:10:41 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*key_value(t_list *env, char *key)
{
	while (env)
	{
		if (ft_strcmp(((t_env *)env->data)->key, key) == 0)
			return (((t_env *)env->data)->value);
		env = env->next;
	}
	return (NULL);
}

int	cd_builtin(t_cmd *cmd)
{
	t_program	*shell;
	char		*path;
	int			ret;

	shell = get_shell();
	path = ((t_exec_cmd *)cmd)->argv[1];
	if (path == NULL)
	{
		if (!check_key(shell->expo, "HOME"))
		{
			printf("minishell: cd: HOME not set\n");
			return (1);
		}
		else
			path = key_value(shell->expo, "HOME");
	}
	ret = chdir(path);
	if (ret == -1)
		return (printf("minishell: cd: %s: %s\n", path, strerror(errno)), 1);
	else
		change_value_both(shell->env, shell->expo, "PWD", getcwd(NULL, 0));
	return (0);
}
