/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:51:29 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/09 17:51:32 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
@tpaesch : cd updated noch nicht $OLDPWD

Testcase:
cd ..
cd $OLDPWD
pwd
*/

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
	update_dir(&shell->env, &shell->expo);
	return (0);
}


void	update_dir(t_list **env, t_list **expo)
{
	char	*tmp;
	char	*path;
	char	*old_path;

	ft_free(key_value(*expo, "OLDPWD"));
	old_path = key_value(*expo, "PWD");
	tmp = getcwd(NULL, 0);
	path = ft_strdup(tmp);
	free(tmp);
	if (!check_key(*env, "OLDPWD"))
		add_env(env, ft_strdup("OLDPWD"), old_path);
	change_value_both(*env, *expo, "OLDPWD", old_path);
	change_value_both(*env, *expo, "PWD", path);
}
