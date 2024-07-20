/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:18:47 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/16 11:07:06 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_scan(t_program *shell, char *input)
{
	int		i;
	char	*delim;
	char	*eof;
	char	*out;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '<' && input[i + 1] == '<')
		{
			i += 2;
			if (input[i] == '<')
				//error and exit fork here
			eof = ft_strdup(&input[i]);
			delim = arg_check(eof);
			heredoc_loop(eof);
			out = ft_strdup(&eof[size]);
			free(eof);
		}
		i++;
	}
}

void	heredoc_loop(char *eof)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		// have to put input into file 
		if (ft_strcmp(line, eof) == 0)
		{
			free(line);
			break ;
		}
		ft_free(line);
	}
}


// have to create fork and wait for signals through readline...
// have to create a file and put the input into the file, maybe to do multiple string
// put them into the file and then stop after string and continue after putting it into the file