/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:07:38 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/01 15:37:15 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_print(char **argv, bool *n_flag)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1] != NULL && *argv[i] != '\0')
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (*n_flag != true)
		ft_putchar_fd('\n', 1);
}

// removed for Norm:
/*
	if (!ft_strnstr(argv[0], "echo", ft_strlen(argv[0])))
		ft_panic("routed to builtin echo, but argv[0] is not '*echo'", 99);
*/
int	echo_builtin(t_cmd *cmd)
{
	char				**argv;
	bool				n_flag;
	unsigned int		i;
	unsigned int		j;
	static const char	*remove = "";

	argv = ((t_exec_cmd *)cmd)->argv;
	n_flag = false;
	i = 1;
	while (argv[i])
	{
		if (*argv[i] == '-')
		{
			j = 1;
			while (argv[i][j] == 'n')
				j++;
			if (argv[i][j] == '\0')
			{
				n_flag = true;
				argv[i] = (char *)remove;
			}
		}
		i++;
	}
	return (echo_print(argv, &n_flag), 0);
	// add return/exit value handling here?
}
