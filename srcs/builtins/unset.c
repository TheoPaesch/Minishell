/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:49:17 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/30 18:15:31 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Verifies if a given key is valid for unset operation.
 *
 * Checks if the key is non-null, not empty, starts with an alphabet or
 * underscore, and contains only alphabets and underscores.
 * Returns 1 if valid, 0 otherwise.
 *
 * @param key The key string to verify.
 * @return int 1 if the key is valid, 0 if invalid.
 */
static int	unset_verify_key(char *key)
{
	if (!key || *key == '\0' || (!ft_isalpha(*key) && *key != '_'))
		return (0);
	while (*key && (ft_isalpha(*key) || *key == '_'))
		key++;
	if (*key == '\0')
		return (1);
	else
		return (0);
}

/**
 * @brief Executes the unset command for the given keys.
 *
 * Iterates over the keys provided in the command arguments, verifying each key
 * before attempting to unset it from both the environment and export variables.
 * Sets the exit value to 1 and prints an error for invalid keys.
 *
 * @param cmd The command structure containing the keys to unset.
 * @return int The exit value
 * 				0 if all keys are successfully unset
 * 				1 if any key is invalid.
 */
int	unset_builtin(t_cmd *cmd)
{
	t_program	*shell;
	char		**keys;
	int			i;
	int			exit_value;

	i = 1;
	exit_value = 0;
	shell = get_shell();
	keys = ((t_exec_cmd *)cmd)->argv;
	while (keys[i])
	{
		if (!unset_verify_key(keys[i]))
		{
			errno = 1;
			exit_value = 1;
			print_err_unset(keys[i++]);
			continue ;
		}
		unset_both(&(shell->env), &(shell->expo), keys[i]);
		i++;
	}
	return (exit_value);
}
