/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:18:47 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/30 16:18:22 by tpaesch          ###   ########.fr       */
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
		tmp = ft_strjoin("tmp/heredoc", c);
		hrdc->file = ft_strjoin(tmp, ".txt");
		if (access(hrdc->file, F_OK) == 0)
		{
			i++;
			tmp = ft_free(tmp);
			hrdc->file = ft_free(hrdc->file);
		}
		else
			break ;
	}
	tmp = ft_free(tmp);
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
		i += output_quotes(&input[i], &out[i]);
		if (input[i] == '<' && input[i + 1] == '<')
		{
			out = fill_out(out, i, input, hrdc);
			break ;
		}
		out[i] = input[i];
		i++;
	}
	hrdc->full_arg = ft_free(hrdc->full_arg);
	return (out);
}

char	*heredoc_scan(char *input, t_heredoc *hrdc)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		i += in_quotes(&input[i]);
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
	set_normal_signal();
	return (hrdc->out);
}

void	heredoc_loop(t_heredoc *hrdc)
{
	char		*line;
	int			fd;
	t_program	*shell;

	set_heredoc_signal();
	fd = open(hrdc->file, O_RDWR | O_CREAT | O_APPEND, 0644);
	shell = get_shell();
	while (1)
	{
		if (g_sig_break)
			break ;
		if (shell->isatty)
			line = readline("> ");
		else
		{
			line = get_next_line(fileno(stdin));
			if (line != NULL)
				line = ft_strtrim(line, "\n");
		}
		if (line == NULL || g_sig_break)
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
	char		*out;
	int			i;
	t_heredoc	*hrdc;

	hrdc = ft_calloc(sizeof(t_heredoc), 1);
	out = input;
	i = 0;
	while (input[i] != '\0')
	{
		i += in_quotes(&input[i]);
		if (input[i] == '<' && input[i + 1] == '<')
		{
			out = heredoc_scan(input, hrdc);
			if (out == NULL || out[0] == '\0')
				return (NULL);
			else
			{
				input = ft_strdup(out);
				i = 0;
				continue ;
			}
		}
		i++;
	}
	return (out);
}
