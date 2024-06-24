/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:52:25 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/24 14:47:50 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	patch_list(t_list *tmp)
{
	t_list	*tmp2;

	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	ft_free(tmp2);
}

void	free_content(t_list *tmp)
{
	ft_free(((t_env *)tmp->data)->key);
	ft_free(((t_env *)tmp->data)->value);
	ft_free(tmp->data);
	tmp->data = NULL;
}

void	unset_one(t_list *env, t_list *expo, char *key)
{
	t_list	*tmp;

	tmp = NULL;
	while (env)
	{
		if (ft_strcmp(((t_env *)env->data)->key, key) == 0)
		{
			free_content(env);
			patch_list(tmp);
		}
		tmp = env;
		env = env->next;
	}
	while (expo)
	{
		if (ft_strcmp(((t_env *)expo->data)->key, key) == 0)
		{
			free_content(expo);
			patch_list(tmp);
		}
		tmp = env;
		expo = expo->next;
	}
}

void	unset(t_exec_cmd *exec_cmd)
{
	t_program	*shell;
	char		**keys;
	int			i;

	i = 0;
	shell = get_shell();
	keys = exec_cmd->argv;
	while (keys[i])
	{
		unset_one(shell->env, shell->expo, *keys);
		i++;
	}
}

t_list	*pre_pointer(t_list *env, char *key)
{
	t_list	*tmp;

	tmp = NULL;
	while (env)
	{
		if (ft_strcmp(((t_env *)env->next->data)->key, key) == 0)
			return (tmp);
		tmp = env;
		env = env->next;
	}
	return (NULL);
}

void	del_env(t_list *env, char *key)
{
	t_list	*tmp;

	tmp = NULL;
	while (env)
	{
		if (ft_strcmp(((t_env *)env->data)->key, key) == 0)
		{
			tmp = pre_pointer(env, key);
			free_content(env);
			patch_list(tmp);
		}
		env = env->next;
	}
}

/*if strcmp finds string to remove,
	return pointer to previous list enrty for removal*/