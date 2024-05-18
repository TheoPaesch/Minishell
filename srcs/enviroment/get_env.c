/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:50:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/18 18:57:56 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "minishell.h"

void	ft_get_input(char **envp)
{
	int		i;
	s_env	*data;
	s_list	*env;
	s_list	*expo;

	i = 0;
	if (ft_lstnew(env) == NULL)
		printf("Error: malloc failed in get_env\n");
	if (ft_lstnew(expo) == NULL)
		printf("Error: malloc failed in get_env\n");
	while (*envp[i] != NULL)
	{
		if (!ft_malloc(&data, sizeof(s_env)))
			return (printf("Error: malloc failed in get_env\n"));
		data->key = ft_strcdup(envp[i], '=', 0);
		data->value = ft_strcdup(envp[i], '=', 1);
		env->data = data;
		expo->data = data;
		ft_lstaddfront(env, ft_lstnew(env));
		ft_lstaddfront(expo, ft_lstnew(expo));
		i++;
	}
}

// check if key filled and value empty, then dont get into env

char	*ft_strcdup(char *str, char c, bool side)
{
	int		i;
	char	*new;

	i = 0;
	if (side == 0)
	{
		while (str[i] != c)
		{
			new[i] = str[i];
			i++;
		}
	}
	else
	{
		while (str[i] != c)
			i++;
		i++;
		while (str[i] != '\0')
		{
			new[i] = str[i];
			i++;
		}
	}
	new[i] = '\0';
	return (new);
}
/* build linked list for env ad fill with befor "=" and after*/