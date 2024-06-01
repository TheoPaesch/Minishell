/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:37 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/29 11:30:31 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_program	shell;
	char		*input;

	if (ac > 1 && av[1] != NULL)
		printf("minishell: no arguments needed\n");
	else
	{
		signal(SIGINT, handle_sigint);
		signal(SIGINT, SIG_IGN);
		printf("reached main here\n");
		fill_program(&shell, envp);
		while (1)
		{
			input = ft_read_input(&shell);
			add_history(input);
			free(input);
		}
	}
}
