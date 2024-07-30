/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:26:53 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/30 20:27:23 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_err(char *str)
{
	if (errno != 0)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
	}
}

// maybe add '+=' case
int	expo_verify_arg(char *arg)
{
	if (!ft_isalpha(*arg) && *arg != '_')
		return (0);
	while (*arg && (ft_isalnum(*arg) || *arg == '_'))
		arg++;
	if (*arg == '\0')
		return (1);
	if (*arg && *arg == '=' && (ft_isprint_no_space((*(arg + 1))) || *(arg
				+ 1) == '\0'))
		return (1);
	if (*arg && *arg == '+' && *(arg + 1) && *(arg + 1) == '='
		&& (ft_isprint_no_space((*(arg + 2))) || *(arg + 2) == '\0'))
		return (1);
	return (0);
}
