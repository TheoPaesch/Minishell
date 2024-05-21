/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:37 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/21 21:04:24 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_program	shell;
	char		*input;

	if (ac > 1)
		printf("minishell: no arguments needed\n");
	else if (ac == 1 && av[1] != NULL)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGINT, SIG_IGN);
		fill_program(&shell, envp);
		while (1)
		{
			input = ft_read_input(&shell);
			add_history(input);
			free(input);
		}
	}
}
