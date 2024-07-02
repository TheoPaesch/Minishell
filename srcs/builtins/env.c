/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:45:38 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/01 19:47:15 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_list *env)
{
	while (env && env->data != NULL && env->next != NULL)
	{
		printf("%s=%s\n", ((t_env *)env->data)->key,
			((t_env *)env->data)->value);
		env = env->next;
	}
}

void	add_env(t_list *env, char *key, char *value)
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
}

// ENV does NOT support options or arguments
int	env_builtin(t_cmd *cmd)
{
	char	**argv;

	argv = ((t_exec_cmd *)cmd)->argv;
	if (argv[1] != NULL)
	{
		printf("env command does not support options or arguments\n");
		return (1);
	}
	else
		print_env((get_shell())->env);
	return (0);
}
