/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:37 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/24 18:27:43 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	null_shell(t_program *shell)
{
	shell->env = NULL;
	shell->expo = NULL;
	shell->mem = NULL;
	shell->ex_status = 0;
	shell->last_exit_code = 0;
	shell->isatty = 0;
}

void	fill_program(t_program *shell, char **envp)
{
	null_shell(shell);
	init_global(shell);
	// shell->mem = new_list(); // wtf
	init_mem_man((t_list **)(&(shell->mem)));
	ft_malloc(1);
	ft_free(NULL);
	// shell->env = ft_lstnew(NULL);
	// shell->expo = ft_lstnew(NULL);
	if (envp[0] == NULL)
		empty_env();
	else
		get_input(envp, &shell->env, &shell->expo);
	if (shell->env == NULL || shell->expo == NULL)
		exit(1);
	get_path((char *)(&(shell->env)));
	shell->last_exit_code = 0;
	shell->ex_status = 0;
	shell->isatty = isatty(STDIN_FILENO);
}

int	main(int ac, char **av, char **envp)
{
	t_program	shell;
	char		*input;

	(void)ac;
	(void)av;
	fill_program(&shell, envp);
	splash_screen(&shell);
	signal(SIGINT, handle_sigint);
	while (1)
	{
		input = read_input(&shell);
		if (input == NULL /*&& !isatty(STDIN_FILENO)*/)
		{
			input = ft_free(input);
			ms_exit(shell.ex_status); // ADD ACTUAL EXIT CODE
		}
		if (*input == '\0')
			continue ;
		add_history(input);
		(input = heredoc_base(input));
		if (input != NULL)
			execute_cmd(print_tree(parse_cmd(ft_strdup(input))));
		input = ft_free(input);
	}
	return (shell.last_exit_code);
}

// have to return input so I take the delimiter from the input and then pass the rest
// have to check that export with no env stll creates env
// if (ac > 1 && av[1] != NULL)
// 	printf("minishell: no arguments needed\n");