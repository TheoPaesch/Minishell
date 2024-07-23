/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:52:25 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/22 20:26:13 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// @brief Takes the PREVIOUS node to the one to be deleted as an argument
/// @param tmp
void	patch_list(t_list *tmp)
{
	t_list	*tmp2;

	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	ft_free(tmp2);
}

void	free_content(t_list *tmp)
{
	if (!tmp)
		return ;
	ft_free(((t_env *)tmp->data)->key);
	ft_free(((t_env *)tmp->data)->value);
	ft_free(tmp->data);
	tmp->data = NULL;
}

void	unset_both(t_list **env, t_list **expo, char *key)
{
	unset_one(env, key);
	unset_one(expo, key);
}

void	unset_one(t_list **lst, char *key)
{
	t_list	*tmp;
	t_list	*prev_node;

	tmp = *lst;
	prev_node = NULL;
	while (tmp)
	{
		if (tmp->data == NULL)
			continue ;
		if (ft_strcmp(((t_env *)tmp->data)->key, key) == 0)
		{
			free_content(tmp);
			if (prev_node == NULL && tmp->next) // may be useless,
				// next condition should be enough
				*lst = NULL;
			else if (prev_node == NULL)
				*lst = tmp->next;
			else
				prev_node->next = tmp->next;
			ft_free(tmp);
			break ;
		}
		prev_node = tmp;
		tmp = tmp->next;
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
			patch_list(tmp); // check if edge case works
		}
		env = env->next;
	}
}

/*if strcmp finds string to remove,
	return pointer to previous list enrty for removal*/