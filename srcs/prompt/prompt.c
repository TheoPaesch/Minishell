/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:25:48 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/27 20:59:10 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_read_input(t_program *mushell)
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