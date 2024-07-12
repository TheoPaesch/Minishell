/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:49:55 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/12 17:47:47 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*trim_input(char *input)
{
	
}

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

char	*get_eof(char *input)
{

}

void	arg_check(char *eof)
{
	char	*arg;
	int		size;
	int		identifier;

	if (eof == NULL)
		return (ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2), 0); // have to exit fork here
	size = def_arg_len(eof, &identifier);
	if ()
	
}
