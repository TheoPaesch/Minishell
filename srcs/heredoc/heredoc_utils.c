/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:49:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/26 22:26:25 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	*arg_check(char *eof, t_heredoc *hrdc)
{
	char	*delimiter;
	int		size;

	if (eof == NULL || *eof == '\0')
		return (p_err(0), NULL);
	size = def_arg_len(eof, hrdc);
	if (size == -1)
		return (NULL);
	delimiter = in_none(eof, size);
	printf("delim arg_check = %s\n", delimiter);
	get_txt(hrdc);
	return (delimiter);
}

void	p_err(int i)
{
	if (i == 0)
		ft_putstr_fd("bash: syntax error\n", 2);
	if (i == 1)
		ft_putstr_fd("bash: error\n", 2);
}

bool	hrdc_line_check(char *line, t_heredoc *hrdc)
{
	if (line == NULL)
		return (1);
	else if (ft_strcmp(line, hrdc->delim) == 0)
		return (1);
	else
		return (0);
}

char	*fill_out(char *out, int i, char *input, t_heredoc *hrdc)
{
	ft_strcpy(&out[i], "< ");
	i += 2;
	ft_strcpy(&out[i], hrdc->file);
	i += len_adjust(&input[i], hrdc);
	// printf("	try to join %s", &input[i]);
	printf("	out pre%s\n", out);
	out = ft_strjoin(out, &input[i]);
	printf("	out post%s\n", out);
	return (out);
}
