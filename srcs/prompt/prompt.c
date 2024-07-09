/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:25:48 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/07 20:10:07 by tpaesch          ###   ########.fr       */
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
			return (ft_free(tmp), NULL);
		free(tmp);
		input = readline(prompt);
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