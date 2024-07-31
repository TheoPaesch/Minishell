/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:50:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/31 13:35:14 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	empty_env(void)
{
	t_program	*shell;
	char		*pwd;
	char		*tmp;

	tmp = getcwd(NULL, 0);
	pwd = ft_strdup(tmp);
	free(tmp);
	shell = get_shell();
	add_export(&shell->env, &shell->expo, ft_strdup("OLDPWD"), NULL);
	add_export(&shell->env, &shell->expo, ft_strdup("PWD"), pwd);
	add_export(&shell->env, &shell->expo, ft_strdup("SHLVL"), ft_strdup("1"));
}

char	*get_key(char *str)
{
	int		i;
	char	*key;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	key = ft_malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] != '=' && str[i] != '\0')
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
	while (str[i] != '=' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (NULL);
	i++;
	j = i;
	while (str[j] != '\0')
		j++;
	if ((str[i] == '"' && str[j] == '"') || (str[i] == 39 && str[j] == 39))
	{
		i++;
		str[--j] = '\0';
	}
	value = ft_malloc(sizeof(char) * (j + 1 - i));
	j = 0;
	while (str[i] != '\0')
		value[j++] = str[i++];
	value[j] = '\0';
	return (value);
}

void	get_input(char **envp, t_list **env, t_list **expo)
{
	int		i;
	t_env	*data1;
	t_env	*data2;

	i = 0;
	while (envp[i] != NULL)
	{
		data1 = ft_malloc(sizeof(t_env));
		data2 = ft_malloc(sizeof(t_env));
		if (!data1 || !data2)
			ft_panic("malloc failed in get_env", 2);
		data1->key = get_key(envp[i]);
		data2->key = get_key(envp[i]);
		data1->value = get_value(envp[i]);
		data2->value = get_value(envp[i]);
		if (data1->value)
			ft_lstadd_back(env, ft_lstnew(data1));
		ft_lstadd_back(expo, ft_lstnew(data2));
		i++;
	}
}
// putting the same mem node in both env and expo. pls fix

// CONSTRUCTOR
// uses normal MALLOC
// does so because it is initialized before ft_malloc
t_list	*new_list(void)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		ft_panic("malloc failed in get_env", 1);
	new->data = NULL;
	new->next = NULL;
	return (new);
}
