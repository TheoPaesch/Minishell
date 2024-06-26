/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:50:04 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/01 15:08:01 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(t_list *expo)
{
	while (expo)
	{
		printf("declare -x %s=\"%s\"\n", ((t_env *)expo->data)->key,
			((t_env *)expo->data)->value);
		expo = expo->next;
	}
}

void	add_export(t_list *env, t_list *expo, char *key, char *value)
{
	t_env	*data;

	data = ft_malloc(sizeof(t_env));
	data->key = key;
	data->value = value;
	if (data->value != NULL)
	{
		env->data = data;
		ft_lstadd_front(&env, ft_lstnew(env));
	}
	expo->data = data;
	ft_lstadd_front(&expo, ft_lstnew(expo));
}

/*export_execution prints export if no argument
	was provided or checks if the key already exitsts
	if so it will change the values,
	if not it will be added to export, if there is a value
	it will also be added to env*/

void	export_execution(t_list *env, t_list *expo, char *key, char *value)
{
	if (key == NULL && value == NULL)
	{
		print_export(expo);
		return ;
	}
	if (check_key(expo, key))
	{
		if (value == NULL)
			return (free(key));
		if (check_key(env, key))
			change_value_both(expo, env, key, value);
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

	shell = get_shell();
	args = ((t_exec_cmd *)cmd)->argv;
	i = 1;
	if (args[i] == NULL)
	{
		export_execution(shell->env, shell->expo, NULL, NULL);
		return (0);
	}
	while (args[i])
	{
		key = get_key(args[i]);
		value = get_value(args[i]);
		export_execution(shell->env, shell->expo, key, value);
		i++;
	}
	return (0);
}
