/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:25:48 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/28 16:45:21 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_input(t_program *mushell)
{
	char	*input;
	char	*prompt;
	char	*tmp;

	(void)mushell;
	if (isatty(STDIN_FILENO))
	{
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
		if (input)
			input[ft_strlen(input) - 1] = '\0'; // revisit this
	}
	return (input);
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