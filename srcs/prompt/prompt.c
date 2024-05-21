/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:25:48 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/21 11:28:39 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_read_input(t_program *mushell)
{
	char	*input;
	char	*prompt;
	char	*tmp;

	if (mushell->isatty)
	{
		prompt = ft_build_prompt();
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
