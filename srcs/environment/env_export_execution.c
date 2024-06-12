/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export_execution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:49:53 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/12 13:55:02 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_export(t_list *expo)
{
	while (expo)
	{
		printf("declare -x %s=\"%s\"\n", ((t_env *)expo->data)->key,
			((t_env *)expo->data)->value);
		expo = expo->next;
	}
}

void	print_env(t_list *env)
{
	while (env)
	{
		printf("%s=%s\n", ((t_env *)env->data)->key,
			((t_env *)env->data)->value);
		env = env->next;
	}
}

bool	check_key(t_list *tmp, char *key)
{
	while (tmp)
	{
		if (ft_strcmp(((t_env *)tmp->data)->key, key) == 0)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	change_value_both(t_list *expo, t_list *env, char *key, char *value)
{
	while (expo)
	{
		if (ft_strcmp(((t_env *)expo->data)->key, key) == 0)
			((t_env *)expo->data)->value = value;
		expo = expo->next;
	}
	while (env)
	{
		if (ft_strcmp(((t_env *)env->data)->key, key) == 0)
		{
			ft_free(&((t_env *)env->data)->value);
			((t_env *)env->data)->value = value;
		}
		env = env->next;
	}
	ft_free(&key);
}

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
			return (ft_free(&key));
		if (check_key(env, key))
			change_value_both(expo, env, key, value);
		else
			add_env(env, key, value);
	}
	else
		add_export(env, expo, key, value);
}

void	add_env(t_list *env, char *key, char *value)
{
	t_env	*data;

	if (!ft_malloc((void **)&data, sizeof(t_env)))
		exit(1);
	data->key = key;
	data->value = value;
	if (data->value != NULL)
	{
		env->data = data;
		ft_lstadd_front(&env, ft_lstnew(env));
	}
}

void	add_export(t_list *env, t_list *expo, char *key, char *value)
{
	t_env	*data;

	if (!ft_malloc((void **)&data, sizeof(t_env)))
		exit(1);
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

/*if value == NULL dont fill env*/