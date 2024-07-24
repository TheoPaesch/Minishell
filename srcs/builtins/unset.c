/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:49:17 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/24 18:19:06 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_builtin(t_cmd *cmd)
{
	t_program	*shell;
	char		**keys;
	int			i;

	i = 1;
	shell = get_shell();
	keys = ((t_exec_cmd *)cmd)->argv;
	while (keys[i])
	{
		if (!unset_verify_key(keys[i]))
		{
			errno = 1;
			print_err(keys[i++]);
			continue ;
		}
		unset_both(&(shell->env), &(shell->expo), keys[i]);
		i++;
	}
	return (errno);
}

int	unset_verify_key(char *key)
{
	if (!key || *key == '\0' || (!ft_isalpha(*key) && *key != '_'))
		return (0);
	while (*key)
	{
		if (!ft_isalnum(*key) && *key != '_')
			return (0);
		key++;
	}
	return (1);
}

// int	expo_verify_arg(char *arg)
// {
// 	if (!ft_isalpha(*arg) && *arg != '_')
// 		return (0);
// 	while (*arg && (ft_isalnum(*arg) || *arg == '_'))
// 		arg++;
// 	if (*arg == '\0')
// 		return (1);
// 	if (*arg && *arg == '=' && (ft_isprint_no_space((*(arg + 1))) || *(arg
// 				+ 1) == '\0'))
// 		return (1);
// 	if (*arg && *arg == '+' && *(arg + 1) && *(arg + 1) == '='
// 		&& (ft_isprint_no_space((*(arg + 2))) || *(arg + 2) == '\0'))
// 		return (1);
// 	return (0);
// }
