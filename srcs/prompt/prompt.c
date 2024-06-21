/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:25:48 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/20 17:23:02 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_input(t_program *mushell)
{
	char	*input;
	char	*prompt;
	char	*tmp;

	if (mushell->isatty)
	{
		tmp = getcwd(NULL, 0);
		prompt = ft_strjoin(tmp, " ");
		if (prompt == NULL)
			return (NULL);
		input = readline(prompt);
		ft_free(tmp);
	}
	else
	{
		tmp = get_next_line(fileno(stdin));
		input = ft_strtrim(tmp, "\n");
		ft_free(tmp);
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