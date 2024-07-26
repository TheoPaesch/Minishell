/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:18:47 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/26 12:45:48 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_txt(t_heredoc *hrdc)
{
	int		i;
	char	*c;
	char	*tmp;

	i = 0;
	while (1)
	{
		c = ft_itoa(i);
		tmp = ft_strjoin("heredoc", c);
		hrdc->file = ft_strjoin(tmp, ".txt");
		if (access(hrdc->file, F_OK) == 0)
		{
			i++;
			ft_free(tmp);
			ft_free(hrdc->file);
		}
		else
			break ;
	}
	ft_free(tmp);
}

char	*adjust_output(t_heredoc *hrdc, char *input)
{
	int		i;
	char	*out;
	bool	condition;

	i = ft_strlen(input) + ft_strlen(hrdc->file) + 2;
	out = ft_calloc(i, sizeof(char));
	condition = heredoc_placement(input, &i, hrdc);
	if (condition)
		return (ft_strjoin(out, &input[i]));
	while (input[i] != '\0')
	{
		if (input[i] == '<' && input[i + 1] == '<')
		{
			i += fill_out(out, i, input, hrdc);
			break ;
		}
		out[i] = input[i];
		i++;
	}
	ft_free(hrdc->full_arg);
	return (out);
}

char	*heredoc_scan(char *input)
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
				return (ft_free(hrdc), NULL);
			while (input[i] == ' ')
				i++;
			hrdc->full_arg = ft_strdup(&input[i]);
			hrdc->delim = arg_check(hrdc->full_arg, hrdc);
			if (hrdc->delim == NULL)
				return (NULL);
			heredoc_loop(hrdc);
			hrdc->out = adjust_output(hrdc, input);
			break ;
		}
		i++;
	}
	return (hrdc->out);
}

void	heredoc_loop(t_heredoc *hrdc)
{
	char	*line;
	int		fd;

	signal(SIGINT, handle_sigint);
	fd = open(hrdc->file, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	t_program *shell = get_shell();
	while (1)
	{
		if (shell->isatty)
			line = readline("> ");
		else
		{
			line = get_next_line(fileno(stdin));
			if (line)
				line[ft_strlen(line) - 1] = '\0';
		}
		if (line == NULL)
			return (close(fd), free(line));
		if (fd == -1 || hrdc_line_check(line, hrdc))
		{
			if (hrdc_line_check(line, hrdc))
				close(fd);
			else
				p_err(1);
			free(line);
			break ;
		}
		if (line != NULL)
			write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	close(fd);
}


char	*heredoc_base(char *input)
{
	char	*out;
	int		i;

	out = input;
	i = 0;
	if (input == NULL)
		return (NULL);
	while (input[i] != '\0')
	{
		if (input[i] == '<' && input[i + 1] == '<')
		{
			out = heredoc_scan(input);
			if (out == NULL)
				return (out);
			else
			{
				input = out;
				i = 0;
			}
		}
		i++;
	}
	return (out);
}

// have to be able to do multiple heredocs
// have to be able to quit with ctrl + d