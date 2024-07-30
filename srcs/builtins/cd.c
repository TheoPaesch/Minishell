/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:51:29 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/30 17:20:43 by mstrauss         ###   ########.fr       */
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

static int	cd_handle_home(t_program *shell, char **new_path)
{
	if (shell->expo && check_key(shell->expo, "HOME") == false)
		return (ft_putstr_fd("bash: cd: HOME not set\n", 2), set_exit_code(1),
			1);
	else
		*new_path = key_value(shell->expo, "HOME");
	return (0);
}

static int	cd_handle_oldpwd(t_program *shell, char **new_path)
{
	if (shell->expo && check_key(shell->expo, "OLDPWD") == false)
		return (ft_putstr_fd("bash: cd: OLDPWD not set\n", 2), set_exit_code(1),
			1);
	*new_path = key_value(shell->expo, "OLDPWD");
	printf("%s\n", *new_path);
	return (0);
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
		if (cd_handle_home(shell, &new_path))
			return (1);
	}
	else if (ft_strcmp(new_path, "-") == 0)
	{
		if (cd_handle_oldpwd(shell, &new_path))
			return (1);
	}
	old_path = getcwd(NULL, 0);
	// error checking here
	ret = chdir(new_path);
	if (ret != 0)
		return (cd_print_err(new_path), free(old_path), 1);
	new_path = getcwd(NULL, 0);
	return (update_dir(&shell->env, &shell->expo, new_path, old_path),
		free(old_path), free(new_path), errno_to_exitcode(errno));
}

void	update_dir(t_list **env, t_list **expo, char *new, char *old)
{
	char	*new_pwd;
	char	*old_pwd;

	new_pwd = ft_strdup(new);
	old_pwd = ft_strdup(old);
	if (check_key(*env, "OLDPWD") == false)
		add_env(env, ft_strdup("OLDPWD"), old_pwd);
	if (check_key(*expo, "OLDPWD") == false)
		add_env(expo, ft_strdup("OLDPWD"), old_pwd);
	if (check_key(*env, "PWD") == false)
		add_env(env, ft_strdup("PWD"), new_pwd);
	if (check_key(*expo, "PWD") == false)
		add_env(expo, ft_strdup("PWD"), new_pwd);
	change_value_both(*expo, *env, "OLDPWD", old_pwd);
	change_value_both(*expo, *env, "PWD", new_pwd);
}
