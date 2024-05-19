/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:50:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/19 16:22:57 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "env.h"

void	ft_epmty_env(void)
{
	struct s_env	*data;
	struct s_list	*env;
	struct s_list	*expo;

	if (ft_lstnew(env) == NULL)
		printf("Error: malloc failed in get_env\n");
	if (ft_lstnew(expo) == NULL)
		printf("Error: malloc failed in get_env\n");
	add_export(env, expo, "OLDPWD", NULL);
	add_export(env, expo, "PWD", getcwd(NULL, 0));
	add_export(env, expo, "SHLVL", "1");
}

void	ft_get_input(char **envp)
{
	int				i;
	struct s_env	*data;
	struct s_list	*env;
	struct s_list	*expo;

	i = 0;
	if (ft_lstnew(env) == NULL)
		printf("Error: malloc failed in get_env\n");
	if (ft_lstnew(expo) == NULL)
		printf("Error: malloc failed in get_env\n");
	while (*envp[i] != NULL)
	{
		if (!ft_malloc(&data, sizeof(struct s_env)))
			return (printf("Error: malloc failed in get_env\n"));
		data->key = ft_strcdup(envp[i], '=', 0);
		data->value = ft_strcdup(envp[i], '=', 1);
		if (data->value[0] != '\0')
		{
			env->content = data;
			ft_lstaddfront(env, ft_lstnew(env));
		}
		expo->content = data;
		ft_lstaddfront(expo, ft_lstnew(expo));
		i++;
	}
}

static char	*ft_strcdup(char *str, char c, bool side)
{
	int		i;
	char	*new;

	i = 0;
	if (side == 0)
	{
		while (str[i] != c || str[i] != '\0')
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