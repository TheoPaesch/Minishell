/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:18:47 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/10 16:49:45 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_arg(char *input)
{
	char	*str;
	int		len;
	char	tmp;

	len = 0;
	str = NULL;
	while (input[len] != ' ' && input[len] != '\0')
		len++;
	if (!len)
		return (NULL);
	tmp = input[len];
	input[len] = '\0';
	str = ft_strdup(input);
	input[len] = tmp;
	return (str);
}

void	heredoc_scan(t_program *shell, char *input)
{
	int		i;
	char	*eof;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '<' && input[i + 1] == '<' && input[i + 2] != '<')
		{
			i += 2;
			while (input[i] == ' ')
				i++;
			eof = get_arg(input + i);
			heredoc_loop(eof);
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