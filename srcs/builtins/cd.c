/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:51:29 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/21 19:27:52 by mstrauss         ###   ########.fr       */
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
	char		*new_path;
	char		*old_path;
	int			ret;

	shell = get_shell();
	new_path = ((t_exec_cmd *)cmd)->argv[1];
	if (new_path == NULL || ft_strcmp(new_path, "~") == 0)
	{
		if (shell->expo && check_key(shell->expo, "HOME") == false)
			return (ft_putstr_fd("bash: cd: HOME not set\n", 2),
				set_exit_status(1), 1);
		else
			new_path = key_value(shell->expo, "HOME");
	}
	else if (ft_strcmp(new_path, "-") == 0)
	{
		if (shell->expo && check_key(shell->expo, "OLDPWD") == false)
			return (ft_putstr_fd("bash: cd: OLDPWD not set\n", 2),
				set_exit_status(1), 1);
		new_path = key_value(shell->expo, "OLDPWD");
		printf("%s\n", new_path);
	}
	old_path = getcwd(NULL, 0);
	ret = chdir(new_path);
	if (ret != 0)
		return (ft_putstr_fd("bash: cd: ", 2), ft_putstr_fd(new_path, 2),
			ft_putstr_fd(strerror(errno), 2), ft_putchar_fd('\n', 2), 1);
	return (update_dir(&shell->env, &shell->expo, new_path, old_path), 0);
}

void	update_dir(t_list **env, t_list **expo, char *new, char *old)
{
	char	*new_pwd;
	char	*old_pwd;

	new_pwd = ft_strdup(new);
	old_pwd = old;
	ft_free(key_value(*expo, "OLDPWD"));
	if (check_key(*env, "OLDPWD") == false)
		add_env(env, ft_strdup("OLDPWD"), old_pwd);
	if (check_key(*expo, "OLDPWD") == false)
		// does OLDPWD even get added to expo? / is this correct behavior?
		add_env(expo, ft_strdup("OLDPWD"), old_pwd);
	change_value_both(*expo, *env, "OLDPWD", old_pwd);
	change_value_both(*expo, *env, "PWD", new_pwd);
}
