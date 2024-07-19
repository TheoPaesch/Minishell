/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:36:38 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/19 11:35:09 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	in_single(char *input, char *output, int *i, int *j)
{
	(*i)++;
	while (input[*i] != 39)
	{
		output[*j] = input[*i];
		(*i)++;
		(*j)++;
	}
	(*i)++;
}

void	in_double(char *input, char *output, int *i, int *j)
{
	(*i)++;
	while (input[*i] != 34)
	{
		output[*j] = input[*i];
		(*i)++;
		(*j)++;
	}
	(*i)++;
}


char	*in_none(char *input, int len)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_malloc(len + 1);
	while (input[i] != ' ' && input[i] != '\0')
	{
		if (input[i] == 39)
			in_single(input, str, &i, &j);
		else if (input[i] == 34)
			in_double(input, str, &i, &j);
		if (input[i] == ' ' || input[i] == '\0')
			break ;
		str[j++] = input[i++];
	}
	str[i] = '\0';
	return (str);
}
