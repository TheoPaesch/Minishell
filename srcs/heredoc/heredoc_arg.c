/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:36:38 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/12 17:43:19 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*in_double(char *input, int len)
{
	char	*str;
	int		i;
	int		amount;

	i = 0;
	amount = 0;
	str = ft_malloc(len + 1);
	while (amount != 2)
	{
		if (input[i] == 34)
			amount++;
		str[i] = input[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*in_single(char *input, int len)
{
	char	*str;
	int		i;
	int		amount;

	i = 0;
	amount = 0;
	str = ft_malloc(len + 1);
	while (amount != 2)
	{
		if (input[i] == 39)
			amount++;
		str[i] = input[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*in_none(char *input, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_malloc(len + 1);
	while (input[i] != ' ')
	{
		str[i] = input[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
