/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:15:38 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/24 18:27:18 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_exit(int code)
{
	t_program	*shell;

	shell = get_shell();
	if (code != -124)
		shell->ex_status = code;
	ft_lstclear(&(shell->mem), free);
	rl_clear_history();
	if (shell->last_exit_code != 0)
	{
		// ft_putstr_fd("exit: using last_exit_code: ", shell->last_exit_code);
		// // dbg
		// ft_putstr_fd(ft_itoa(shell->last_exit_code), 2);
		// ft_putchar_fd('\n', 2);
		exit(shell->last_exit_code); // not dbg
	}
	else
	{
		// ft_putstr_fd("exit: using ex_status: ", 2); // dbg
		// ft_putstr_fd(ft_itoa(shell->ex_status), 2);
		// ft_putchar_fd('\n', 2);
		exit(shell->ex_status); // not dbg
	}
}

void	parse_exit(char *arg, t_program *shell)
{
	int	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
		{
			ft_putstr_fd("bash: ", 2);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd(": ", 2);
			ft_putstr_fd("numeric argument required\n", 2);
			shell->ex_status = 255;
			ms_exit(shell->ex_status);
		}
		else
			i++;
	}
}

void	exit_builtin(t_cmd *cmd)
{
	t_program	*shell;
	char		**args;
	int			tmp;

	shell = get_shell();
	args = ((t_exec_cmd *)cmd)->argv;
	if (args[1] != NULL)
	{
		parse_exit(args[1], shell);
		if (args[2] != NULL)
		{
			printf("exit\nminishell: exit: too many arguments\n");
			return ;
		}
		tmp = ft_atoi(args[1]);
		tmp = tmp % 256;
		shell->ex_status = tmp;
	}
	ms_exit(0); // ADD ACTUAL EXIT CODE
}

/* ---------- EXIT TEST CASES --------- */
/*

exit 9223372036854775807

exit something somethingv2

exit 0 0

exit

exit ""

exit "+100"

exit "-100"

exit -9223372036854775805

exit 0

exit 10

exit 42

exit 1

exit +++++

exit ++++++

exit +1

exit ++1

exit ++12560

exit -----

exit ------

exit -1

exit --1

exit -12560

exit --12560

exit 255

exit 1 2

exit 1 2 3

exit A

exit A 2 3

exit "A"

exit "+++"

exit ++++3193912939

exit 01

exit 001

exit 0001

exit +++000

exit ++++000

exit ---000

exit ----000

exit "something"

exit x

exit echo

exit cd ..

exit exit

exit 42 42 42 42 42

*/