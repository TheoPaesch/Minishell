/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exp_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:27:37 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/29 15:15:14 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_value_both(t_list *expo, t_list *env, char *key, char *value)
{
	t_env	*test;

	while (expo)
	{
		test = expo->data;
		if (test != NULL)
			if (ft_strcmp(test->key, key) == 0)
				((t_env *)expo->data)->value = value;
		if (test == NULL || ft_strcmp(test->key, key) == 0)
			break ;
		expo = expo->next;
	}
	while (env)
	{
		test = env->data;
		if (test != NULL)
			if (ft_strcmp(test->key, key) == 0)
				((t_env *)env->data)->value = value;
		if (test == NULL || ft_strcmp(test->key, key) == 0)
			break ;
		env = env->next;
	}
	key = ft_free(key);
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
