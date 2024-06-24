/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exp_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:27:37 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/24 14:33:35 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			ft_free(((t_env *)env->data)->value);
			((t_env *)env->data)->value = value;
		}
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
