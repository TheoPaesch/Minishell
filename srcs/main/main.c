/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:37 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/02 20:56:27 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_program(t_program *shell, char **envp)
{
	init_global(shell);
	shell->mem = new_list();
	init_mem_man((t_list **)(&(shell->mem)));
	ft_malloc(1);
	ft_free(NULL);
	shell->env = ft_lstnew(NULL);
	shell->expo = ft_lstnew(NULL);
	if (envp[0] == NULL)
		empty_env();
	else
		get_input(envp, &shell->env, &shell->expo);
	if (shell->env == NULL || shell->expo == NULL)
		exit(1);
	get_path((char *)(&(shell->env)));
	shell->last_exit_code = 0;
	shell->ex_status = 0;
	shell->isatty = isatty(fileno(stdin));
}

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
		add_history(input);
		execute_cmd(parse_cmd(ft_strdup(input)));
	}
	return (shell.last_exit_code);
	// }
}


//have to check that export with no env stll creates env