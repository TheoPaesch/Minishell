/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:25:48 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/14 19:00:13 by mstrauss         ###   ########.fr       */
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
		tmp = getcwd(NULL, 0);
		printf("tmp: %s\n", tmp);
		input = ft_strdup(" ");
		prompt = ft_strjoin(tmp, input);
		printf("prompt: %s\n", prompt);
		if (prompt == NULL)
			return (NULL);
		input = readline(prompt);
		// prompt = ft_free(prompt); // yeet this to get rid of dblfree
	}
	else
	{
		tmp = get_next_line(STDIN_FILENO);
		input = ft_strtrim(tmp, "\n");
		// tmp = ft_free(tmp);
	}
	return (input);
}

// getcwd is malloced keep in mind to free