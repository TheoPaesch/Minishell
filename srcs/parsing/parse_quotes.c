/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:02:20 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/31 19:02:57 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_parse_quotes(t_parse_quotes_vars *v, char **quote)
{
	v->tmp_ptr = *quote;
	v->return_value = ft_malloc(sizeof(char) * MAX_STR_LEN);
	v->start_rtrn = v->return_value;
	*quote = v->start_rtrn;
	v->in_single_quote = false;
	v->in_double_quote = false;
}

bool	pq_handle_quotes(t_parse_quotes_vars *v)
{
	if (*v->tmp_ptr == '\'' && !v->in_double_quote)
	{
		v->in_single_quote = !v->in_single_quote;
		v->tmp_ptr++;
		return (true);
	}
	if (*v->tmp_ptr == '"' && !v->in_single_quote)
	{
		v->in_double_quote = !v->in_double_quote;
		v->tmp_ptr++;
		return (true);
	}
	return (false);
}

bool	pq_handle_expand(t_parse_quotes_vars *v)
{
	if (*v->tmp_ptr == '$' && ft_strchr("\'\"", *(v->tmp_ptr + 1))
		&& !v->in_single_quote && !v->in_double_quote)
	{
		v->tmp_ptr++;
		return (true);
	}
	if (*v->tmp_ptr == '~' && !v->in_single_quote && !v->in_double_quote)
	{
		v->return_value += ft_strlcpy(v->return_value,
				expand_tilde(&v->tmp_ptr), MAX_STR_LEN);
		return (true);
	}
	else if (*v->tmp_ptr == '$' && !v->in_single_quote && ((v->in_double_quote
				|| !v->in_double_quote) && (*(v->tmp_ptr + 1) == '_'
				|| isalpha(*(v->tmp_ptr + 1)) || *(v->tmp_ptr + 1) == '?')))
	{
		v->return_value += ft_strlcpy(v->return_value, expand_var(&v->tmp_ptr),
				MAX_STR_LEN);
		return (true);
	}
	return (false);
}

char	*parse_quotes(char **quote, char **end_quote)
{
	t_parse_quotes_vars	v;

	init_parse_quotes(&v, quote);
	while (v.tmp_ptr < *end_quote)
	{
		if (pq_handle_quotes(&v))
			continue ;
		if (pq_handle_expand(&v))
			continue ;
		else
			*v.return_value++ = *v.tmp_ptr++;
	}
	*v.return_value = '\0';
	*end_quote = v.return_value;
	return (v.start_rtrn);
}
