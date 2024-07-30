/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:49:50 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/30 18:18:39 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*parse_cmd(char *str)
{
	char	*end_str;
	t_cmd	*cmd;

	end_str = str + ft_strlen(str);
	cmd = parse_line(&str, end_str);
	scan_skip_ws(&str, end_str, "\0");
	if (str != end_str)
		ft_debug_msg("parse_cmd has leftover chars in str\n");
	nullterm(cmd);
	return (cmd);
}

/*
ATTENTION:
Due to the way the subject is formulated, it seems as if handling
lists and background execution is EXPLICITLY FORBIDDEN.
So we removed it.
Clarification in the subject would be appreciated.

*/

t_cmd	*parse_line(char **ptr_str, char *end_str)
{
	t_cmd	*cmd;

	cmd = parse_pipe(ptr_str, end_str);
	while (scan_skip_ws(ptr_str, end_str, "&"))
	{
		get_token(ptr_str, end_str, 0, 0);
		cmd = init_back_cmd(cmd);
	}
	if (scan_skip_ws(ptr_str, end_str, ";"))
	{
		get_token(ptr_str, end_str, 0, 0);
		cmd = list_cmd(cmd, parse_line(ptr_str, end_str));
	}
	return (cmd);
}

t_cmd	*parse_pipe(char **ptr_str, char *end_str)
{
	t_cmd	*cmd;

	cmd = parse_exec(ptr_str, end_str);
	if (scan_skip_ws(ptr_str, end_str, "|"))
	{
		get_token(ptr_str, end_str, 0, 0);
		cmd = pipe_cmd(cmd, parse_pipe(ptr_str, end_str));
	}
	return (cmd);
}

// IDEA:
// export R="   R"
// check if word contains a var "WO"$R"D
// expand $VAR
// return to beginning and treat expanded str as seperate tokens
t_cmd	*parse_exec(char **ptr_str, char *end_str)
{
	t_parse_exec_vars	v;

	if (scan_skip_ws(ptr_str, end_str, "("))
		return (parse_block(ptr_str, end_str));
	v.retrn_val = init_exec_cmd();
	v.cmd = (t_exec_cmd *)v.retrn_val;
	v.argc = 0;
	v.retrn_val = parse_redir(v.retrn_val, ptr_str, end_str);
	while (!scan_skip_ws(ptr_str, end_str, "|)&;"))
	{
		v.type = get_token(ptr_str, end_str, &v.quote, &v.end_quote);
		if (v.type == 0)
			break ;
		if (v.type == '"' || v.type == '\'')
			parse_quotes(&v.quote, &v.end_quote, &v.type);
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
	v.cmd->argv[v.argc] = NULL;
	v.cmd->end_argv[v.argc] = NULL;
	// if (argv[0] = NULL && scan_skip_ws(ptr_str, end_str, "|)&;"))
	// if(argv[0] = 0) && scan_skip_ws( , , "operators") then:
	// bash: syntax error near unexpected token `|'
	// for '| grep hello' handle errror here? output:
	// bash: syntax error near unexpected token `|'
	// using scan_skip_ws();
	return (v.retrn_val);
}

// int	validate_cmd_table(char **ptr_str, char *end_str, char **argv)
// {
// 	return (1);
// }

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

/*
PLAN:
allocate long string in return_val
iterate over string, copying if no special condition is met
DONT copy the current quote type if within quotes
expand $ and ~
advance start_ptr past the expanded var / symbol
continue copying to end
*/
// TODO: add reallocation
char	*parse_quotes(char **quote, char **end_quote, int *type)
{
	char	*return_value;
	char	*start_rtrn;
	char	*tmp_ptr;
	bool	in_single_quote;
	bool	in_double_quote;

	tmp_ptr = *quote;
	return_value = ft_malloc(sizeof(char) * MAX_STR_LEN);
	start_rtrn = return_value;
	*quote = start_rtrn;
	in_single_quote = false;
	in_double_quote = false;
	while (tmp_ptr < *end_quote)
	{
		if (*tmp_ptr == '\'')
		{
			if (!in_double_quote)
			{
				in_single_quote = !in_single_quote;
				tmp_ptr++;
				continue ;
			}
		}
		else if (*tmp_ptr == '"')
		{
			if (!in_single_quote)
			{
				in_double_quote = !in_double_quote;
				tmp_ptr++;
				continue ;
			}
		}
		else if (*tmp_ptr == '$' && ft_strchr("\'\"", *(tmp_ptr + 1))
				&& !in_single_quote && !in_double_quote)
		{
			tmp_ptr++;
			continue ;
		}
		if (*tmp_ptr == '~' && !in_single_quote && !in_double_quote)
			return_value += ft_strlcpy(return_value, expand_tilde(&tmp_ptr),
					MAX_STR_LEN);
		else if (*tmp_ptr == '$' && !in_single_quote && ((in_double_quote
					|| !in_double_quote) && (*(tmp_ptr + 1) == '_'
					|| isalpha(*(tmp_ptr + 1)) || *(tmp_ptr + 1) == '?')))
			return_value += ft_strlcpy(return_value, expand_var(&tmp_ptr),
					MAX_STR_LEN);
		else
			*return_value++ = *tmp_ptr++;
	}
	*return_value = '\0';
	*end_quote = return_value;
	// *type = 'x';
	(void)type;
	return (start_rtrn);
}

// && ft_isalnum(*(tmp_ptr + 1))

// if (quote)
// 	*quote = tmp_ptr;

// if (end_quote)
// 	*end_quote = tmp_ptr;

t_cmd	*parse_block(char **ptr_str, char *end_str)
{
	t_cmd	*cmd;

	if (!scan_skip_ws(ptr_str, end_str, "("))
		ft_debug_msg("expected '('\n"); // dbg
	get_token(ptr_str, end_str, 0, 0);
	cmd = parse_line(ptr_str, end_str);
	if (!scan_skip_ws(ptr_str, end_str, ")"))
		ft_debug_msg("expected ')'\n"); // dbg
	get_token(ptr_str, end_str, 0, 0);
	cmd = parse_redir(cmd, ptr_str, end_str);
	return (cmd);
}

// '+' is >>
t_cmd	*parse_redir(t_cmd *cmd, char **ptr_str, char *end_str)
{
	t_parse_redir_vars	v;

	while (scan_skip_ws(ptr_str, end_str, "<>"))
	{
		v.type = get_token(ptr_str, end_str, 0, 0);
		if (get_token(ptr_str, end_str, &v.quote, &v.end_quote) != 'x')
			ft_panic("Can't redirect. Filename missing.", 2);
		if (v.type == '<')
		{
			cmd = init_redir_cmd(cmd, v.quote, v.end_quote, O_RDONLY | O_CREAT);
			((t_redir_cmd *)cmd)->fd = 0;
		}
		else if (v.type == '>')
		{
			cmd = init_redir_cmd(cmd, v.quote, v.end_quote, O_WRONLY | O_CREAT);
			((t_redir_cmd *)cmd)->fd = 1;
		}
		else if (v.type == '+')
		{
			cmd = init_redir_cmd(cmd, v.quote, v.end_quote, O_WRONLY | O_CREAT);
			((t_redir_cmd *)cmd)->fd = 1;
		}
	}
	return (cmd);
}
