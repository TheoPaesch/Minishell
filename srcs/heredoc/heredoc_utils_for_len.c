/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils_for_len.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:47:44 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/23 14:49:12 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	count_in_single(char *eof, int *i, int *amount)
{
	*i += 1;
	while (eof[*i] != 39)
	{
		if (eof[*i] == '\0')
			return (p_err(0), 0);
		*i += 1;
	}
	*amount += 2;
	return (1);
}

bool	count_in_double(char *eof, int *i, int *amount)
{
	*i += 1;
	while (eof[*i] != 34)
	{
		if (eof[*i] == '\0')
			return (p_err(0), 0);
		*i += 1;
	}
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
		if (eof[i] != '\0')
			i++;
	}
	hrdc->size = i;
	return (i - amount);
}

