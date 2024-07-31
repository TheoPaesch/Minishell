/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:18:47 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/31 18:30:50 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	line = NULL;
	if (shell->isatty)
		hd_loop_tty(hrdc, line, fd);
	else
		hd_loop_nontty(hrdc, line, fd);
	close(fd);
	line = ft_free(line);
}

void	hd_loop_tty(t_heredoc *hrdc, char *line, int fd)
{
	if (fd == -1)
		p_err(1);
	while (g_sig_break == 0)
	{
		line = readline("> ");
		if (line == NULL || g_sig_break)
			return ;
		if (hrdc_line_check(line, hrdc))
			return ;
		if (line != NULL)
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
		}
		line = ft_free(line);
	}
}

void	hd_loop_nontty(t_heredoc *hrdc, char *line, int fd)
{
	if (fd == -1)
		p_err(1);
	while (g_sig_break == 0)
	{
		line = get_next_line(STDIN_FILENO);
		if (line != NULL)
			line = ft_strtrim(line, "\n");
		if (line == NULL || g_sig_break)
			return ;
		if (hrdc_line_check(line, hrdc))
			return ;
		if (line != NULL)
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
		}
		line = ft_free(line);
	}
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
