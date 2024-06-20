/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:37 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/20 17:22:57 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_program	shell;
	char		*input;

	(void)ac;
	(void)av;
	// if (ac > 1 && av[1] != NULL)
	// 	printf("minishell: no arguments needed\n");
	// else
	// {
	fill_program(&shell, envp);
	splash_screen(&shell);
	signal(SIGINT, handle_sigint);
	while (1)
	{
		input = read_input(&shell);
		if (input == NULL)
			ms_exit(&shell);
		execute_cmd(parse_cmd(ft_strdup(input)));
		add_history(input);
	}
	// }
}
