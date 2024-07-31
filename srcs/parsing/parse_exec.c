/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:03:50 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/31 19:05:53 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pe_init_vars(t_parse_exec_vars *v, char **ptr_str, char *end_str)
{
	v->retrn_val = init_exec_cmd();
	v->cmd = (t_exec_cmd *)v->retrn_val;
	v->argc = 0;
	v->retrn_val = parse_redir(v->retrn_val, ptr_str, end_str);
}

t_cmd	*parse_exec(char **ptr_str, char *end_str)
{
	t_parse_exec_vars	v;

	if (scan_skip_ws(ptr_str, end_str, "("))
		return (parse_block(ptr_str, end_str));
	pe_init_vars(&v, ptr_str, end_str);
	while (!scan_skip_ws(ptr_str, end_str, "|)&;"))
	{
		v.type = get_token(ptr_str, end_str, &v.quote, &v.end_quote);
		if (v.type == 0)
			break ;
		if (v.type == '"' || v.type == '\'')
			parse_quotes(&v.quote, &v.end_quote);
		if (!(v.type == 'x' || v.type == '"' || v.type == '\''))
			ft_panic("get_token returned UNKNOWN type", 100);
		if (v.type == 'x')
			expand_word(&v.quote, &v.end_quote, &v.type);
		v.cmd->argv[v.argc] = v.quote;
		v.cmd->end_argv[v.argc] = v.end_quote;
		v.argc++;
		if (v.argc >= MAXARGS)
			ft_panic("Amount of Arguments > MAXARGS", 505);
		v.retrn_val = parse_redir(v.retrn_val, ptr_str, end_str);
	}
	return (v.cmd->argv[v.argc] = NULL, v.cmd->end_argv[v.argc] = NULL,
		v.retrn_val);
}

char	*expand_word(char **start, char **end, int *type)
{
	char	*tmp;
	char	*return_value;
	char	*start_rtrn;

	tmp = *start;
	return_value = ft_malloc(sizeof(char) * MAX_STR_LEN);
	*start = return_value;
	start_rtrn = *start;
	while (tmp < *end)
	{
		if (*tmp == '$' && *(tmp + 1) != '\0')
			return_value += ft_strlcpy(return_value, expand_var(&tmp),
					MAX_STR_LEN);
		else if (*tmp == '~')
			return_value += ft_strlcpy(return_value, expand_tilde(&tmp),
					MAX_STR_LEN);
		else
			*return_value++ = *tmp++;
	}
	*return_value = '\0';
	*end = return_value;
	*type = 'x';
	return (start_rtrn);
}
