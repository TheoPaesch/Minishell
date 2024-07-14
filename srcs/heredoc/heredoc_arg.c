/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:36:38 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/14 20:56:21 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*in_double(char *input)
{
	char	*str;
	int		i;

	i = 0;
	while (input[i] != 34)
	{
		str[i] = input[i];
		i++;
	}
	return (str);
}

char	*in_single(char *input)
{
	char	*str;
	int		i;

	i = 0;
	while (input[i] != 39)
	{
		str[i] = input[i];
		i++;
	}
	return (str);
}

char	*in_none(char *input, int len)
{
	char	*tmp;
	char	*str;
	int		i;

	i = 0;
	str = ft_malloc(len + 1);
	while (input[i] != ' ' && input[i] != '\0')
	{
		if (input[i] == 39)

		str[i] = input[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}


// trim arg doesnt work like this have to trim the quotes from the string prior
// have to use funtions so I can determine the string in quotes, malloc it and then add it to the existing line without quotes.
char	*trim_input(char *arg)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	i = 1;
	j = 0;
	len = ft_strlen(arg);
	str = ft_malloc(len - 1);
	while (i < len - 1)
	{
		str[j] = arg[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

