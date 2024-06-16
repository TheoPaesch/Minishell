/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:37 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/16 18:50:45 by tpaesch          ###   ########.fr       */
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
		fill_program(&shell, envp);
		signal(SIGINT, handle_sigint);
		while (1)
		{
			input = read_input(&shell);
			if (input == NULL)
				ms_exit(&shell);
			add_history(input);
		}
	}
}
