/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:07:38 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/28 15:23:43 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_print(char **argv, bool *n_flag, int first_word)
{
	int	i;

	i = first_word;
	while (argv[i] != NULL)
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1] != NULL)
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (*n_flag != true)
		ft_putchar_fd('\n', 1);
}

int	echo_builtin(t_cmd *cmd)
{
	char			**argv;
	bool			n_flag;
	unsigned int	i;
	unsigned int	j;

	argv = ((t_exec_cmd *)cmd)->argv;
	if (argv[1] == NULL)
		return (ft_putchar_fd('\n', 1), 0);
	n_flag = false;
	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] == 'n')
	{
		j = 1;
		while (argv[i][j] == 'n')
			j++;
		if (argv[i][j] == '\0')
		{
			n_flag = true;
			i++;
		}
		else
			break ;
	}
	return (echo_print(argv, &n_flag, i), 0);
}

// while (argv[++i])
// {
// 	if (*argv[i] == '-')
// 	{
// 		j = 1;
// 		while (argv[i][j] == 'n')
// 			j++;
// 		if (argv[i][j] == '\0' && argv[i][j - 1] == 'n')
// 		{
// 			n_flag = true;
// 			argv[i] = (char *)remove;
// 			break ;
// 		}
// 	}
// }