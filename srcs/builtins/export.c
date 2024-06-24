/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:50:04 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/24 14:45:50 by mstrauss         ###   ########.fr       */
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
