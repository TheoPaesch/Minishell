/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export_execution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:49:53 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/19 14:30:03 by tpaesch          ###   ########.fr       */
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

void	prtint_env(t_list *env)
{
	while (env)
	{
		printf("%s=%s\n", ((t_env *)env->data)->key,
			((t_env *)env->data)->value);
		env = env->next;
	}
}

void	add_export(t_list *env, t_list *expo, char *key, char *value)
{
	t_env	*data;

	if (!ft_malloc(&data, sizeof(t_env)))
		return (printf("Error: malloc failed in add_export\n"));
	data->key = key;
	data->value = value;
	if (data->value[0] != '\0')
	{
		env->data = data;
		ft_lstaddfront(env, ft_lstnew(env));
	}
	expo->data = data;
	ft_lstaddfront(expo, ft_lstnew(expo));
}
