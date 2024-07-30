/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:33:20 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/30 22:27:59 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_value_of_key(t_list *lst, char *key)
{
	while (lst)
	{
		if (lst->data != NULL && ft_strcmp(((t_env *)lst->data)->key, key) == 0)
			return (((t_env *)(lst->data))->value);
		lst = lst->next;
	}
	return (NULL);
}

char	*expand_exit_stat(void)
{
	return (ft_itoa(get_shell()->last_exit_code));
}

// currently only gets called in quote handling
// needs to be called outside of quotes too.
char	*expand_tilde(char **ptr)
{
	t_list	*env;
	char	*exp_str;

	if (**ptr != '~')
		ft_panic("expand_tilde received string without ~", 420);
	exp_str = NULL;
	env = (t_list *)(get_shell()->env);
	if (*(*ptr + 1) == '/' || *(*ptr + 1) == '\0' || ft_strchr(" \t\r\n\v ",
			**ptr))
		expand_tilde_helper(env, &exp_str);
	else
	{
		exp_str = ft_malloc(sizeof(char) * 2);
		ft_strlcpy(exp_str, "~", 2);
	}
	if (ptr)
		(*ptr)++;
	return (exp_str);
}

void	expand_tilde_helper(t_list *env, char **exp_str)
{
	int	len;

	while (env)
	{
		if (ft_strcmp(((t_env *)(env->data))->key, "HOME") == 0)
		{
			len = ft_strlen(((t_env *)(env->data))->value);
			*exp_str = ft_malloc(sizeof(char) * len + 1);
			ft_strlcpy(*exp_str, ((t_env *)(env->data))->value, len + 1);
			break ;
		}
		env = env->next;
	}
}

// static char	*exp_var_get_value(t_list *lst, char *trmd)
// {
// 	while (lst && *trmd != '\0')
// 	{
// 		if (lst->data != NULL && ft_strcmp(((t_env *)lst->data)->key,
// 				trmd) == 0)
// 			return (ft_free(trmd), ((t_env *)lst->data)->value);
// 		lst = lst->next;
// 	}
// 	return (NULL);
// }

// NOTES:
// prefers values from export over environment.
// if key found in exp immediately returns
char	*expand_var(char **str)
{
	char	*tmp;
	char	*trmd;

	if (**str != '$')
		ft_panic("expand_var received string without $", 420);
	if (*(*str + 1) == '?' || *(*str + 1) == '\0' || !ft_isalnum(*(*str + 1)))
	{
		if (*(*str + 1) == '?')
			return (*str += 2, expand_exit_stat());
		else
			return (*str += 1, ft_strdup("$"));
	}
	*str += 1;
	tmp = *str;
	while (ft_isalnum(**str) || **str == '_')
		(*str)++;
	trmd = ft_substr(tmp, 0, *str - tmp);
	tmp = get_value_of_key(get_shell()->env, trmd);
	if (tmp)
		return (tmp);
	tmp = get_value_of_key(get_shell()->expo, trmd);
	if (tmp)
		return (tmp);
	return (ft_free(trmd), NULL);
}
