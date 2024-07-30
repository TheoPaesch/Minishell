/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:33:20 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/30 21:57:43 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Iterates over a STR,
 * checking if there is an even number of single and double quotes.
 * @param str str to be checked
 * @return  1 if all opened quotes are closed
 * 			0 if the str contains unclosed quotes
 */
int	check_valid_quotes(char *str)
{
	char	*tmp;
	int		single_q;
	int		double_q;

	single_q = 0;
	double_q = 0;
	tmp = str;
	while (*tmp != '\0')
	{
		if (*tmp == 39)
			single_q += 1;
		if (*tmp == 34)
			double_q += 1;
		tmp++;
	}
	if (single_q % 2 != 0 || double_q % 2 != 0)
		return (0);
	else
		return (1);
}

char	*get_value_of_key(t_list *lst, char *key)
{
	while (lst)
	{
		if (ft_strcmp(((t_env *)(lst->data))->key, key) == 0)
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
	int		len;

	if (**ptr != '~')
		ft_panic("expand_tilde received string without ~", 420);
	exp_str = NULL;
	env = (t_list *)(get_shell()->env);
	if (*(*ptr + 1) == '/' || *(*ptr + 1) == '\0' || ft_strchr(" \t\r\n\v ",
			**ptr))
	{
		while (env)
		{
			if (ft_strcmp(((t_env *)(env->data))->key, "HOME") == 0)
			{
				len = ft_strlen(((t_env *)(env->data))->value);
				exp_str = ft_malloc(sizeof(char) * len + 1);
				ft_strlcpy(exp_str, ((t_env *)(env->data))->value, len + 1);
				break ;
			}
			env = env->next;
		}
	}
	else
	{
		exp_str = ft_malloc(sizeof(char) * 2);
		ft_strlcpy(exp_str, "~", 2);
	}
	if (ptr)
		(*ptr)++;
	return (exp_str);
}

// NOTES:
// prefers values from export over environment.
// if key found in exp immediately returns
char	*expand_var(char **str)
{
	t_list	*env;
	t_list	*exp;
	char	*start;
	char	*trmd;

	env = get_shell()->env;
	exp = get_shell()->expo;
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
	start = *str;
	while (ft_isalnum(**str) || **str == '_')
		(*str)++;
	trmd = ft_substr(start, 0, *str - start);
	while (exp && *trmd != '\0')
	{
		if (exp->data != NULL && ft_strcmp(((t_env *)exp->data)->key,
				trmd) == 0)
			return (ft_free(trmd), ((t_env *)exp->data)->value);
		exp = exp->next;
	}
	while (env && *trmd != '\0')
	{
		if (env->data != NULL && ft_strcmp(((t_env *)env->data)->key,
				trmd) == 0)
			return (ft_free(trmd), ((t_env *)env->data)->value);
		env = env->next;
	}
	return (ft_free(trmd), NULL);
}
