/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:25:48 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/31 14:52:03 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_input(t_program *shell)
{
	char	*input;
	char	*prompt;
	char	*tmp;

	(void)shell;
	if (shell->isatty == true)
	{
		restore_fds(shell);
		tmp = getcwd(NULL, 0);
		prompt = ft_strjoin(tmp, "$ ");
		if (prompt == NULL)
			return (free(tmp), tmp = NULL, NULL);
		free(tmp);
		tmp = NULL;
		input = readline(prompt);
		prompt = ft_free(prompt);
	}
	else
	{
		input = get_next_line(fileno(stdin));
		if (input != NULL)
			input = ft_strtrim(input, "\n");
	}
	return (input);
}

void	restore_fds(t_program *shell)
{
	if (shell->isatty == true)
	{
		dup2(shell->orig_stdin, STDIN_FILENO);
		dup2(shell->orig_stdout, STDOUT_FILENO);
	}
}

// if	(isatty(fileno(stdin)))
// 	shell->prompt = readline(shell->terminal_prompt);
// else
// {
// 	char *line;
// 	line = get_next_line(fileno(stdin));
// 	shell->prompt = ft_strtrim(line, "\n");
// 	free(line);
// }
// getcwd is malloced keep in mind to free