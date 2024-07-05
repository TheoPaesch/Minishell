/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:33:20 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/05 16:49:55 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* ---------------------------------- TODO: --------------------------------- */
/*
- currently expanding without consideration of being inside of quotes.
- ~
- $?
*/

/// @brief Iterates over a STR, checking if there is an Even Number of
///        Single and Double quotes.
/// @param str Str to be checked
/// @return 1 if all opened quotes are closed
///			0 if the str contains unclosed quotes
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
		if (*tmp == 39) // = single quote
			single_q += 1;
		if (*tmp == 34) // = double quote
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

char	*expand_tilde(void)
{
	t_list	*env;
	char	*exp_str;
	int		len;

	env = (t_list *)(get_shell()->env);
	while (env)
	{
		if (ft_strcmp(((t_env *)(env->data))->key, "HOME"))
		// check if strcmp best sol
		{
			len = ft_strlen(((t_env *)(env->data))->value);
			exp_str = ft_malloc(sizeof(char) * len + 1);
			ft_strlcpy(exp_str, ((t_env *)(env->data))->value, len);
		}
		env = env->next;
	}
	return (exp_str);
}

// NOTES:
// prefers values from export over environment.
// if key found in exp immediately returns
char	*expand_var(char *str)
{
	t_list	*env;
	t_list	*exp;
	char	*trimmed;
	int		i;

	env = get_shell()->env;
	exp = get_shell()->expo;
	i = 0;
	if (str[i] != '$')
		ft_panic("expand_var received string without $", 420);
	i++;
	if (str[i] == '?')
		return (expand_exit_stat());
	while (ft_isalnum(str[i]))
		i++;
	trimmed = ft_substr(str, 1, i - 1);
	while (exp)
	{
		if (ft_strcmp(((t_env *)exp->data)->key, trimmed) == 0)
			return (((t_env *)exp->data)->value);
		exp = exp->next;
	}
	while (env)
	{
		if (ft_strcmp(((t_env *)env->data)->key, trimmed) == 0)
			return (((t_env *)env->data)->value);
		env = env->next;
	}
	return (NULL); // check if expanding to empty string is more correct ""
}

// void	expand_argv(t_exec_cmd *exec_cmd)
// {
// 	int		i;
// 	char	**argv;
// 	char	*start;
// 	char	*end;
// 	char	*expanded_var;

// 	argv = exec_cmd->argv;
// 	i = -1;
// 	while (argv[++i])
// 	{
// 		if (check_valid_quotes(argv[i]) != 1)
// 			ft_panic("unclosed quotes", 420);
// 		start = ft_strchr(argv[i], '$');
// 		if (start != NULL)
// 		{
// 			end = start;
// 			while (*end == '$' || ft_isalnum(*end))
// 				end++;
// 			expanded_var = expand_var(start);
// 			*start = '\0';
// 			if (*end != '\0')
// 				*end++ = '\0';
// 			argv[i] = ft_strjoinall(3, 0, argv[i], expanded_var, end);
// 		}
// 	}
// }

// BONUS
// void	expand_wildcards(void)
// {
// }

// whitespace beachten / fehlender whitespace / nicht splitten
// echo hallo"$test123"
