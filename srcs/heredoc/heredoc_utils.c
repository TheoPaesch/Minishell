/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:49:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/13 15:47:37 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//have to also add that you can have more quotes than two, so muliple strings attached to each other
int	def_arg_len(char *eof, int *identifier)
{
	int	i;

	i = 0;
	while (eof[i] != ' ' && eof[i] != '\0')
	{
		if (eof[i] == 39 && *identifier == 0)
		{
			*identifier = 1;
			while (eof[i] != 39)
			{
				if (eof[i] == '\0')
					return (ft_putstr_fd("minishell: syntax error\n", 2), 0); // have to exit fork here
				i++;
			}
		}
		if (eof[i] == 34 && *identifier == 0)
		{
			while (eof[i] != 34)
			{
				if (eof[i] == '\0')
					return (ft_putstr_fd("minishell: syntax error\n", 2), 0); // have to exit fork here
				i++;
			}
			*identifier = 2;
		}
		i++;
	}
	return (i);
}

// use identifier to see == 0 not in quotes, == 1 in single quotes, == 2 in double quotes

void	arg_check(char *eof)
{
	char	*arg;
	int		size;
	int		identifier;

	if (eof == NULL || *eof == '\0')
		return (ft_putstr_fd("minishell: syntax error\n", 2), 0); // have to exit fork here
	size = def_arg_len(eof, &identifier);
	if (identifier == 0)
		arg = in_none(eof, size);
	if (identifier == 1)
		arg = in_single(eof, size);
	if (identifier == 2)
		arg = in_double(eof, size);
}

char	*trim_output(char *arg)
{

}
