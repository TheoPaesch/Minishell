/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:50:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/21 21:03:25 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_epmty_env(void)
{
	struct s_env	*data;
	struct s_list	*env;
	struct s_list	*expo;

	data = NULL;
	env = NULL;
	expo = NULL;
	if (ft_lstnew(env) == NULL)
		printf("Error: malloc failed in get_env\n");
	if (ft_lstnew(expo) == NULL)
		printf("Error: malloc failed in get_env\n");
	add_export(env, expo, "OLDPWD", NULL);
	add_export(env, expo, "PWD", getcwd(NULL, 0));
	add_export(env, expo, "SHLVL", "1");
}

static char	*ft_strcdup(char *str, char c, bool side)
{
	int		j;
	int		i;
	char	*new;

	new = NULL;
	j = 0;
	i = 0;
	if (side == 0)
		while (str[i] != c || str[i] != '\0')
			new[j++] = str[i++];
	else
	{
		while (str[i] != c)
			i++;
		i++;
		while (str[i] != '\0')
			new[j++] = str[i++];
	}
	new[i] = '\0';
	return (new);
}

void	ft_get_input(char **envp, struct s_list *env, struct s_list *expo)
{
	int		i;
	t_env	*data;

	i = 0;
	if (ft_lstnew(env) == NULL)
		printf("Error: malloc failed in get_env\n");
	if (ft_lstnew(expo) == NULL)
		printf("Error: malloc failed in get_env\n");
	while (envp[i] != NULL)
	{
		if (!ft_malloc((void **)&data, sizeof(struct s_env)))
			printf("Error: malloc failed in get_env\n");
		data->key = ft_strcdup(envp[i], '=', 0);
		data->value = ft_strcdup(envp[i], '=', 1);
		if (data->value[0] != '\0')
		{
			env->content = data;
			ft_lstadd_front(&env, ft_lstnew(env));
		}
		expo->content = data;
		ft_lstadd_front(&expo, ft_lstnew(expo));
		i++;
	}
}

/* build linked list for env ad fill with befor "=" and after*/

void	fill_program(t_program *shell, char **envp)
{
	if (envp == NULL)
		ft_epmty_env();
	else
		ft_get_input(envp, shell->env, shell->expo);
	if (shell->env == NULL || shell->expo == NULL)
		exit(1);
	shell->ex_status = false;
	shell->isatty = isatty(STDIN_FILENO);
}
