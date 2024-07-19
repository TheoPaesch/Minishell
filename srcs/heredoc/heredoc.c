/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:18:47 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/18 16:32:30 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*heredoc_scan(t_program *shell, char *input)
{
	int		i;
	char	*delim;
	char	*eof;
	char	*out;
	int		size;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '<' && input[i + 1] == '<')
		{
			i += 2;
			if (input[i] == '<')
				return (ft_putstr_fd("minishell: syntax error\n", 2), NULL);
			while (input[i] == ' ')
				i++;
			eof = ft_strdup(&input[i]);
			delim = arg_check(eof);
			if (delim == NULL)
				return (NULL);
			heredoc_loop(delim);
			out = ft_strdup(&eof[size]);
			free(eof);
		}
		i++;
	}
	return (out);
}

void	heredoc_loop(char *eof)
{
	char	*line;
	int		fd;

	signal(SIGINT, handle_sigint);
	while (1)
	{
		line = readline("> ");
		if (ft_strcmp(line, eof) == 0)
		{
			free(line);
			break ;
		}
		fd = open("heredoc.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
		if (fd == -1)
			ft_putstr_fd("minishell: error\n", 2); // have to exit fork here
		if (line != NULL)
			write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		close(fd);
		ft_free(line);
	}
}


// have to create heredoc struct to save lines
// have to parce the output and adjust the output so it will be to matthias liking
// have to create fork and wait for signals through readline...
// have to create a file and put the input into the file, maybe to do multiple string
// put them into the file and then stop after string and continue after putting it into the file