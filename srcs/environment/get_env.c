/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:50:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/20 19:03:45 by mstrauss         ###   ########.fr       */
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

// static char	*ft_strcdup(char *str, char c, bool side)
// {
// 	int		j;
// 	int		i;
// 	char	*new;

// 	new = NULL;
// 	j = 0;
// 	i = 0;
// 	if (side == 0)
// 		while (str[i] != c || str[i] != '\0')
// 			new[j++] = str[i++];
// 	else
// 	{
// 		while (str[i] != c)
// 			i++;
// 		i++;
// 		while (str[i] != '\0')
// 			new[j++] = str[i++];
// 	}
// 	new[i] = '\0';
// 	return (new);
// }

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

/* build linked list for env ad fill with befor "=" and after*/

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

void	fill_program(t_program *shell, char **envp)
{
	shell->mem = new_list();
	init_mem_man((t_list **)(&(shell->mem)));
	ft_malloc(1);
	ft_free(NULL);
	get_path((char *)(&(shell->env)));
	if (envp == NULL)
		empty_env();
	else
		get_input(envp, &shell->env, &shell->expo);
	if (shell->env == NULL || shell->expo == NULL)
		exit(1);
	shell->ex_status = false;
	shell->isatty = isatty(fileno(stdin));
}
