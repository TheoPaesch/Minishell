/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:10:55 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/30 17:19:13 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Attention: used in export!
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

void	print_err_unset(char *str)
{
	if (errno != 0)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd("unset: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
	}
}

void	cd_print_err(char *str)
{
	if (errno != 0)
	{
		ft_putstr_fd("bash: cd: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
	}
}
