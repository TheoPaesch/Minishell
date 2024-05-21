/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export_execution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:49:53 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/21 18:56:38 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_export(t_list *expo)
{
	while (expo)
	{
		printf("declare -x %s=\"%s\"\n", ((t_env *)expo->content)->key,
			((t_env *)expo->content)->value);
		expo = expo->next;
	}
}

void	prtint_env(t_list *env)
{
	while (env)
	{
		printf("%s=%s\n", ((t_env *)env->content)->key,
			((t_env *)env->content)->value);
		env = env->next;
	}
}

void	add_export(t_list *env, t_list *expo, char *key, char *value)
{
	t_env	*data;

	if (!ft_malloc((void **)&data, sizeof(t_env)))
		printf("Error: malloc failed in add_export\n");
	data->key = key;
	data->value = value;
	if (data->value[0] != '\0')
	{
		env->content = data;
		ft_lstadd_front(&env, ft_lstnew(env));
	}
	expo->content = data;
	ft_lstadd_front(&expo, ft_lstnew(expo));
}


/* have to add, that if key is the same, overwrite the current value also have to handle unset to delete*/