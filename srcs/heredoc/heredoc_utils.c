/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:49:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/23 15:06:05 by tpaesch          ###   ########.fr       */
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
	get_txt(hrdc);
	return (delimiter);
}

void	p_err(int i)
{
	if (i == 0)
		ft_putstr_fd("minishell: syntax error\n", 2);
	if (i == 1)
		ft_putstr_fd("minishell: error\n", 2);
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
