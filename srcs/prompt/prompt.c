/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:25:48 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/11 15:33:41 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*read_input(t_program *mushell)
{
	char	*input;
	char	*prompt;
	char	*tmp;

	if (mushell->isatty)
	{
		prompt = getcwd(NULL, 0);
		if (prompt == NULL)
			return (NULL);
		input = readline(prompt);
		free(prompt);
	}
	else
	{
		tmp = get_next_line(STDIN_FILENO);
		input = ft_strtrim(tmp, "\n");
		free(tmp);
	}
	return (input);
}

// getcwd is malloced keep in mind to free