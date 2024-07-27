/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:50:04 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/27 15:49:45 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(t_list *expo)
{
	char	*key;
	char	*value;

	while (expo && expo->data != NULL)
	{
		key = ((t_env *)expo->data)->key;
		value = ((t_env *)expo->data)->value;
		if (value != NULL)
			printf("declare -x %s=\"%s\"\n", key, value);
		else
			printf("declare -x %s\n", key);
		expo = expo->next;
	}
}

void	add_export(t_list **env, t_list **expo, char *key, char *value)
{
	t_env	*data;

	data = ft_malloc(sizeof(t_env));
	data->key = key;
	data->value = value;
	if (data->value != NULL)
		ft_lstadd_back(env, ft_lstnew(data));
	ft_lstadd_back(expo, ft_lstnew(data));
}

/*export_execution prints export if no argument
	was provided or checks if the key already exitsts
	if so it will change the values,
	if not it will be added to export, if there is a value
	it will also be added to env*/

void	export_execution(t_list **env, t_list **expo, char *key, char *value)
{
	if (key == NULL && value == NULL)
	{
		print_export(*expo);
		return ;
	}
	if (check_key(*expo, key))
	{
		if (value == NULL)
			return (free(key));
		if (check_key(*env, key))
			change_value_both(*expo, *env, key, value);
		else
			add_env(env, key, value);
	}
	else
		add_export(env, expo, key, value);
}

/*export buildin checks if there are arguments
	to export and executes them in order*/

int	export_builtin(t_cmd *cmd)
{
	t_program	*shell;
	int			i;
	char		*key;
	char		*value;
	char		**args;

	errno = 0;
	shell = get_shell();
	args = ((t_exec_cmd *)cmd)->argv;
	i = 1;
	if (args[i] == NULL || (!ft_strcmp("-p", args[i]) && args[i + 1] == NULL))
		return (print_export(shell->expo), errno);
	while (args[i])
	{
		if (!expo_verify_arg(args[i]))
		{
			errno = 1; // set errno here for illegal arg
			if (*args[i] == '-')
				errno = 2;
			print_err(args[i++]);
			continue ;
		}
		key = get_key(args[i]);
		value = get_value(args[i++]);
		export_execution(&shell->env, &shell->expo, key, value);
	}
	return (errno);
}

void	print_err(char *str)
{
	if (errno != 0)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
	}
}

// maybe add '+=' case
int	expo_verify_arg(char *arg)
{
	if (!ft_isalpha(*arg) && *arg != '_')
		return (0);
	while (*arg && (ft_isalnum(*arg) || *arg == '_'))
		arg++;
	if (*arg == '\0')
		return (1);
	if (*arg && *arg == '=' && (ft_isprint_no_space((*(arg + 1))) || *(arg
				+ 1) == '\0'))
		return (1);
	if (*arg && *arg == '+' && *(arg + 1) && *(arg + 1) == '='
		&& (ft_isprint_no_space((*(arg + 2))) || *(arg + 2) == '\0'))
		return (1);
	return (1);
}
