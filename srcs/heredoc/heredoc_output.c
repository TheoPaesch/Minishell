/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:30:32 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/31 18:30:56 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*adjust_output(t_heredoc *hrdc, char *input)
{
	int		i;
	char	*out;
	bool	condition;

	i = ft_strlen(input) + ft_strlen(hrdc->file) + 2;
	out = ft_calloc(i, sizeof(char));
	condition = heredoc_placement(input, &i, hrdc);
	if (condition)
		return (ft_strjoin(out, &input[i]));
	while (input[i] != '\0')
	{
		i += output_quotes(&input[i], &out[i]);
		if (input[i] == '<' && input[i + 1] == '<')
		{
			out = fill_out(out, i, input, hrdc);
			break ;
		}
		out[i] = input[i];
		i++;
	}
	hrdc->full_arg = ft_free(hrdc->full_arg);
	return (out);
}
