/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:18:47 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/22 17:02:53 by tpaesch          ###   ########.fr       */
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

void	adjust_output(t_heredoc *hrdc, char *input)
{
	int		i;
	char	*out;

	i = ft_strlen(input) + ft_strlen(hrdc->file) + 2;
	out = ft_calloc(i, sizeof(char));
	i = 0;
	while (input[i] != '\0')
	{
		out[i] = input[i];
		if (input[i] == '<' && input[i + 1] == '<')
		{
			ft_strcpy(&out[i], "< ");
			i += 2;
			ft_strcpy(&out[i], hrdc->file);
			while (input[i] == ' ')
				i++;
			i += hrdc->size;
			out = ft_strjoin(out, &input[i]);
			break ;
		}
		i++;
	}
	hrdc->out = out;
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
				return (p_err(0), ft_free(hrdc), NULL);
			while (input[i] == ' ')
				i++;
			hrdc->full_arg = ft_strdup(&input[i]);
			hrdc->delim = arg_check(hrdc->full_arg, hrdc);
			if (hrdc->delim == NULL)
				return (NULL);
			heredoc_loop(hrdc);
			adjust_output(hrdc, input);
			free(hrdc->full_arg);
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
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			return (close(fd), free(line));
		if (fd == -1 || ft_strcmp(line, hrdc->delim) == 0)
		{
			if (ft_strcmp(line, hrdc->delim) == 0)
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

// have to be able to do multiple heredocs
// have to be able to quit with ctrl + d