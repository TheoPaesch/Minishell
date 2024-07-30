/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:15:38 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/30 20:54:32 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	errno_to_exitcode(int err)
{
	if (err == EACCES)
		return (126);
	if (err == ENOENT)
		return (127);
	if (err == EAGAIN)
		return (128);
	if (err == ENOMEM)
		return (129);
	if (err == EINTR)
		return (130);
	if (err == EINVAL)
		return (2);
	if (err == EIO)
		return (131);
	if (err == 0)
		return (0);
	return (0);
}

void	set_exit_code(int status)
{
	t_program	*shell;

	ft_debug_msg(ft_strjoin("set_exit_code to ", ft_itoa(status)));
	shell = get_shell();
	shell->last_exit_code = status;
}

void	ms_exit(int code)
{
	t_program	*shell;

	ft_debug_msg(ft_strjoin("ms_exit with ", ft_itoa(code)));
	shell = get_shell();
	ft_lstclear(&(shell->mem), free);
	rl_clear_history();
	exit(shell->last_exit_code);
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
			if (isatty(fileno(stdin)))
				ft_putstr_fd("exit", 1);
			ft_putstr_fd("bash: ", 2);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd(": ", 2);
			ft_putstr_fd("numeric argument required\n", 2);
			shell->last_exit_code = 255;
			ms_exit(shell->last_exit_code);
		}
		else
			i++;
	}
}

int	exit_builtin(t_cmd *cmd)
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
			if (isatty(fileno(stdin)))
				ft_putstr_fd("exit\n", 1);
			ft_putstr_fd("bash: ", 2);
			ft_putstr_fd(args[0], 2);
			ft_putstr_fd(": too many arguments\n", 2);
			return (1);
		}
		tmp = ft_atoi(args[1]);
		// add atod to libft for exit 9223372036854775807 testcase (%256 = 255)
		tmp = tmp % 256;
		shell->last_exit_code = tmp;
	}
	ms_exit(shell->last_exit_code);
	return (0);
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