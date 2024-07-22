/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:49:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/21 19:23:02 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// have to check if the rihgt length is returned for malloc
bool	count_in_single(char *eof, int *i, int *amount)
{
	while (eof[*i] != 39)
	{
		if (eof[*i] == '\0')
			return (p_err(0), 0);
		*i += 1;
	}
	*i += 1;
	*amount += 2;
	return (1);
}

bool	count_in_double(char *eof, int *i, int *amount)
{
	while (eof[*i] != 34)
	{
		if (eof[*i] == '\0')
			return (p_err(0), 0);
		*i += 1;
	}
	*i += 1;
	*amount += 2;
	return (1);
}

int	def_arg_len(char *eof, t_heredoc *hrdc)
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	while (eof[i] != ' ' && eof[i] != '\0')
	{
		if (eof[i] == 39)
			if (!count_in_single(eof, &i, &amount))
				return (-1);
		if (eof[i] == 34)
			if (!count_in_double(eof, &i, &amount))
				return (-1);
		i++;
	}
	hrdc->size = i;
	return (i - amount);
}

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
	return (delimiter);
}

void	p_err(int i)
{
	if (i == 0)
		ft_putstr_fd("minishell: syntax error\n", 2);
	if (i == 1)
		ft_putstr_fd("minishell: error\n", 2);
}
