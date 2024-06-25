/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:50:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/24 16:16:31 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	empty_env(void)
{
	t_list	*env;
	t_list	*expo;

	env = NULL;
	expo = NULL;
	if (ft_lstnew(env) == NULL)
		ft_panic("malloc failed in get_env", 1);
	if (ft_lstnew(expo) == NULL)
		ft_panic("malloc failed in get_env", 1);
	add_export(env, expo, "OLDPWD", NULL);
	add_export(env, expo, "PWD", getcwd(NULL, 0));
	add_export(env, expo, "SHLVL", "1");
}

char	*get_key(char *str)
{
	int		i;
	char	*key;

	i = 0;
	while (str[i] != '=')
		i++;
	key = ft_malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] != '=')
	{
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

char	*get_value(char *str)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	j = i;
	while (str[j] != '\0')
		j++;
	value = ft_malloc(sizeof(char) * (j + 1 - i));
	j = 0;
	while (str[i] != '\0')
	{
		value[j] = str[i];
		i++;
		j++;
	}
	value[j] = '\0';
	return (value);
}

void	get_input(char **envp, t_list **env, t_list **expo)
{
	int		i;
	t_env	*data;

	i = 0;
	while (envp[i] != NULL)
	{
		data = ft_malloc(sizeof(t_env));
		if (!data)
			ft_panic("malloc failed in get_env", 1);
		data->key = get_key(envp[i]);
		data->value = get_value(envp[i]);
		if (data->value[0] != '\0')
			ft_lstadd_front(env, ft_lstnew(data));
		ft_lstadd_front(expo, ft_lstnew(data));
		i++;
	}
}

// CONSTRUCTOR
// uses normal MALLOC
// does so because it is initialized before ft_malloc
static t_list	*new_list(void)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		ft_panic("malloc failed in get_env", 1);
	new->data = NULL;
	new->next = NULL;
	return (new);
}
