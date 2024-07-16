/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:49:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/16 11:07:39 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//have to also add that you can have more quotes than two, so muliple strings attached to each other
// have to check if the rihgt length is returned for malloc
int	count_in_single(char *eof)
{
	int	i;

	i = 0;
	while (eof[i] != 39)
	{
		if (eof[i] == '\0')
			return (ft_putstr_fd("minishell: syntax error\n", 2), 0); // have to exit fork here
		i++;
	}
	return (i);
}

int	count_in_double(char *eof)
{
	int	i;

	i = 0;
	while (eof[i] != 34)
	{
		if (eof[i] == '\0')
			return (ft_putstr_fd("minishell: syntax error\n", 2), 0); // have to exit fork here
		i++;
	}
	return (i);
}

int	def_arg_len(char *eof)
{
	int	i;

	i = 0;
	while (eof[i] != ' ' && eof[i] != '\0')
	{
		if (eof[i] == 39)
			i += count_in_single(&eof[i]);
		if (eof[i] == 34)
			i += count_in_double(&eof[i]);
		i++;
	}
	return (i);
}

char	*arg_check(char *eof)
{
	char	*delimiter;
	int		size;
	char	*out;

	if (eof == NULL || *eof == '\0')
		return (ft_putstr_fd("minishell: syntax error\n", 2), 0); // have to exit fork here
	size = def_arg_len(eof);
	delimiter = in_none(eof, size);
	out = ft_strdup(&eof[size]);
	return (delimiter);
}


