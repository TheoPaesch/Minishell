
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:37 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/29 23:13:48 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sig_break = 0;

void	null_shell(t_program *shell)
{
	shell->env = NULL;
	shell->expo = NULL;
	shell->mem = NULL;
	shell->last_exit_code = 0;
	shell->isatty = isatty(fileno(stdin));
}

void	fill_program(t_program *shell, char **envp)
{
	null_shell(shell);
	init_global(shell);
	init_mem_man((t_list **)(&(shell->mem)));
	ft_malloc(1);
	ft_free(NULL);
	if (envp[0] == NULL)
		empty_env();
	else
		get_input(envp, &shell->env, &shell->expo);
	if (shell->env == NULL || shell->expo == NULL)
		exit(1);
	get_path((char *)(&(shell->env)));
	shell->last_exit_code = 0;
	shell->isatty = isatty(STDIN_FILENO);
	shell->orig_stdin = dup(STDIN_FILENO);
	shell->orig_stdout = dup(STDOUT_FILENO);
}

int	main(int ac, char **av, char **envp)
{
	t_program	shell;
	char		*input;

	(void)ac;
	(void)av;
	fill_program(&shell, envp);
	splash_screen(&shell);
	signals_init();
	g_sig_break = 0;
	while (1)
	{
		input = read_input(&shell);
		if (input == NULL)
			ms_exit(shell.last_exit_code);
		if (*input == '\0')
			continue ;
		add_history(input);
		// printf("initial: %s\n", input);
		input = heredoc_base(input);
		// printf("post heredoc: %s\n", input);
		// input = early_expand(input);
		// printf("post expansion: %s\n", input);
		if (input != NULL)
		{
			input = early_expand(input);
			execute_cmd(print_tree(parse_cmd(ft_strdup(input))));
		}
		input = ft_free(input);
	}
	return (shell.last_exit_code);
}

// have to return input so I take the delimiter from the input and then pass the rest
// have to check that export with no env still creates env
// if (ac > 1 && av[1] != NULL)
// 	printf("minishell: no arguments needed\n");

char	*early_expand(char *input)
{
	char	*output;
	char	*start;

	if (!input)
		return (NULL);
	output = ft_calloc(sizeof(char), MAX_STR_LEN);
	start = output;
	while (*input)
	{
		if (*input == '\'')
			copy_through_pair(&output, &input, '\'');
		else if (*input == '"')
			copy_through_pair(&output, &input, '\"');
		else if (*input == '$')
			output += ft_strlcpy(output, expand_var(&input), MAX_STR_LEN);
		else if (*input == '~')
			output += ft_strlcpy(output, expand_tilde(&input), MAX_STR_LEN);
		else
			*output++ = *input++;
	}
	return (start);
}

void	copy_through_pair(char **output, char **input, char sym)
{
	if (*input && **input == sym)
	{
		*(*output)++ = *(*input)++;
		while (*input && **input != sym)
			*(*output)++ = *(*input)++;
		if (*input)
			*(*output)++ = *(*input)++;
	}
}
