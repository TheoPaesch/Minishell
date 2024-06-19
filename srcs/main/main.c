/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:37 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/18 20:16:16 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_program	shell;
	char		*input;

	if (ac > 1 && av[1] != NULL)
		printf("minishell: no arguments needed\n");
	else
	{
		splash_screen();
		fill_program(&shell, envp);
		signal(SIGINT, handle_sigint);
		while (1)
		{
			input = read_input(&shell);
			// printf("input : '%s'\n", input);
			if (input == NULL)
				ms_exit(&shell);
			execute_cmd(parse_cmd(ft_strdup(input)));
			add_history(input);
		}
	}
}
