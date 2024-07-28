/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:36:38 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/28 21:45:13 by tpaesch          ###   ########.fr       */
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
	str = ft_calloc(len + 1, sizeof(char *));
	while (input[i] != ' ' && input[i] != '\0')
	{
		if (input[i] == '<' && input[i + 1] == '<')
			break ;
		if (input[i] == 39)
			in_single(input, str, &i, &j);
		else if (input[i] == 34)
			in_double(input, str, &i, &j);
		else
			str[j++] = input[i++];
		if (ft_strchr("() |$;>", input[i]) || input[i] == '\0')
			break ;
	}
	return (str);
}

int	in_quotes(char *input)
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	if (input[i] == 39)
		count_in_single(input, &i, &amount);
	if (input[i] == 34)
		count_in_double(input, &i, &amount);
	return (i);
}

int	output_quotes(char *input, char *output)
{
	int	i;

	if (input[0] != 39 && input[0] != 34)
		return (0);
	i = 0;
	output[i] = input[i];
	i++;
	if (input[0] == 39)
	{
		while (input[i] != 39)
		{
			output[i] = input[i];
			i++;
		}
	}
	else if (input[0] == 34)
	{
		while (input[i] != 34)
		{
			output[i] = input[i];
			i++;
		}
	}
	output[i] = input[i];
	return (i + 1);
}
