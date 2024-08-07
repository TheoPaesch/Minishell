/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:45:38 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/22 19:30:08 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_list *env)
{
	while (env)
	{
		if (env->data == NULL)
			continue ;
		printf("%s=%s\n", ((t_env *)env->data)->key,
			((t_env *)env->data)->value);
		env = env->next;
	}
}

void	add_env(t_list **env, char *key, char *value)
{
	t_env	*data;

	data = ft_malloc(sizeof(t_env));
	data->key = key;
	data->value = value;
	if (data->value != NULL)
		ft_lstadd_back(env, ft_lstnew(data));
}

// ENV does NOT support options or arguments
int	env_builtin(t_cmd *cmd)
{
	char	**argv;

	argv = ((t_exec_cmd *)cmd)->argv;
	if (argv[1] != NULL)
		return (0);
	else
		print_env((get_shell())->env);
	return (0);
}
