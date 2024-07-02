/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:49:50 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/02 20:21:05 by mstrauss         ###   ########.fr       */
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
		v.token = get_token(ptr_str, end_str, &v.quote, &v.end_quote);
		if (v.token == 0)
			break ;
		if (v.token == '"' || v.token == '\'')
			parse_quotes(v.quote, v.end_quote); // CONTINUE HERE
		if (v.token != 'x')
			// get_token return value for non op
			strerror(1); //"SYNTAX"); // change
		v.cmd->argv[v.argc] = v.quote;
		v.cmd->end_argv[v.argc] = v.end_quote;
		v.argc++;
		if (v.argc >= MAXARGS)
			ft_panic("Amount of Arguments > MAXARGS", 505);
		v.retrn_val = parse_redir(v.retrn_val, ptr_str, end_str);
	}
	v.cmd->argv[v.argc] = 0;
	v.cmd->end_argv[v.argc] = 0;
	return (v.retrn_val);
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
char	*parse_quotes(char *start, char *end)
{
	bool	in_single_quote;
	bool	in_double_quote;
	int		i;

	char *return_value; // ALLOCATE A STR TO THIS AND THEN RETURN IT?
	in_single_quote = false;
	in_double_quote = false;
	i = 0;
	while (*start)
	{
		if (*start == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		else if (*start == '"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		if (*start == '~' && !in_single_quote && !in_double_quote)
			expand_tilde(&start);
		else if (*start == '$' && !in_single_quote)
			expand_var(&start);
		else
			return_value[i] = *start;
		i++;
	}
	return_value[i] = '\0';
	return (return_value);
}

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

t_cmd	*parse_redir(t_cmd *cmd, char **ptr_str, char *end_str)
{
	t_parse_redir_vars	v;

	while (scan_skip_ws(ptr_str, end_str, "<>"))
	{
		v.token = get_token(ptr_str, end_str, 0, 0);
		if (get_token(ptr_str, end_str, &v.quote, &v.end_quote) != 'x')
			ft_panic("Can't redirect. Filename missing.", 2);
		if (v.token == '<')
		{
			init_redir_cmd(cmd, v.quote, v.end_quote, O_RDONLY);
			((t_redir_cmd *)cmd)->fd = 0;
		}
		else if (v.token == '>')
		{
			init_redir_cmd(cmd, v.quote, v.end_quote, O_WRONLY | O_CREAT);
			((t_redir_cmd *)cmd)->fd = 1;
		}
		else if (v.token == '+') // '+' is >>
		{
			init_redir_cmd(cmd, v.quote, v.end_quote, O_WRONLY | O_CREAT);
			((t_redir_cmd *)cmd)->fd = 1;
		}
	}
	return (cmd);
}

// t_cmd	*parse_quotes(char **ptr_str, char *end_str)
// {
// 	t_cmd	*cmd;
// }
