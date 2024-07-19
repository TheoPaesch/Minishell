/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:18:47 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/19 14:44:11 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	adjust_output(t_heredoc *hrdc, char *input)
{
	int		i;
	char	*out;

	i = 0;
	out = ft_calloc(ft_strlen(input), sizeof(char));
	while (input[i] != '\0')
	{
		out[i] = input[i];
		if (input[i] == '<' && input[i + 1] == '<')
		{
			ft_strcpy(&out[i], "< heredoc.txt ");
			i += hrdc->size;
			out = ft_strjoin(out, &input[i]);
			break ;
		}
		i++;
	}
	hrdc->out = out;
}

char	*heredoc_scan(t_program *shell, char *input)
{
	t_heredoc	*hrdc;
	int			i;

	i = 0;
	hrdc = ft_malloc(sizeof(t_heredoc));
	while (input[i] != '\0')
	{
		if (input[i] == '<' && input[i + 1] == '<')
		{
			i += 2;
			if (input[i] == '<')
				return (p_err(0), ft_free(hrdc), NULL);
			while (input[i] == ' ')
				i++;
			hrdc->full_arg = ft_strdup(&input[i]);
			hrdc->delim = arg_check(hrdc->full_arg, hrdc);
			if (hrdc->delim == NULL)
				return (NULL);
			heredoc_loop(hrdc->delim);
			adjust_output(hrdc, input);
			free(hrdc->full_arg);
		}
		i++;
	}
	return (hrdc->out);
}

void	heredoc_loop(char *delim)
{
	char	*line;
	int		fd;

	signal(SIGINT, handle_sigint);
	while (1)
	{
		line = readline("> ");
		fd = open("heredoc.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
		if (fd == -1 || ft_strcmp(line, delim) == 0)
		{
			if (ft_strcmp(line, delim) == 0)
				close(fd);
			else
				p_err(1);
			ft_free(line);
			break ;
		}
		if (line != NULL)
			write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		close(fd);
		ft_free(line);
	}
}


// have to be able to do multiple heredocs
// set right size in struct for heredoc
// adjust the true output for further exec
// have to create heredoc struct to save lines
// have to parce the output and adjust the output so it will be to matthias liking
// have to create fork and wait for signals through readline...
// have to create a file and put the input into the file, maybe to do multiple string
// put them into the file and then stop after string and continue after putting it into the file