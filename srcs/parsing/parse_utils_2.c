/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:53:13 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/03 16:41:11 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*parse_exec(char **ptr_str, char *end_str)
{
	t_parse_exec_vars	v;

	if (scan_skip_ws(ptr_str, end_str, "("))
		return (parse_block(ptr_str, end_str));
	v.retrn_val = exec_cmd();
	v.cmd = (t_exec_cmd *)v.retrn_val;
	v.argc = 0;
	v.retrn_val = parse_redir(v.retrn_val, ptr_str, end_str);
	while (!scan_skip_ws(ptr_str, end_str, "|)&;"))
	{
		v.token = get_token(ptr_str, end_str, &v.quote, &v.end_quote);
		if (v.token == 0)
			break ;
		if (v.token != 'x')  // get_token fake return value
			error("SYNTAX"); // change
		v.cmd->argv[v.argc] = v.quote;
		v.cmd->end_argv[v.argc] = v.end_quote;
		v.argc++;
		if (v.argc >= MAXARGS)
			error("Amount of Arguments > MAXARGS"); // change
		v.retrn_val = parse_redir(v.retrn_val, ptr_str, end_str);
	}
	v.cmd->argv[v.argc] = 0;
	v.cmd->end_argv[v.argc] = 0;
	return (v.retrn_val);
}

t_cmd	*parse_cmd(char *str)
{
	char	*end_str;
	t_cmd	*cmd;

	end_str = str + ft_strlen(str);
	cmd = parse_line(&str, end_str);
	scan_skip_ws(&str, end_str, "\0");
	if (str != end_str)
	{
		printf(2, "Leftovers: %s\n", str); // debugging, remove later
		error();                           // add error function
	}
	nullterm(cmd);
	return (cmd);
}

t_cmd	*parse_redir(t_cmd *cmd, char **ptr_str, char *end_str)
{
	t_parse_redir_vars	v;

	while (scan_skip_ws(ptr_str, end_str, "<>"))
	{
		v.token = get_token(ptr_str, end_str, 0, 0);
		if (get_token(ptr_str, end_str, &v.quote, &v.end_quote) != 'x') // check
			error("Can't redirect. File missing.");
		if (*v.token == '<')
		{
			cmd = redir_cmd(cmd, v.quote, v.end_quote, O_RDONLY);
			((t_redir_cmd *)cmd)->fd = 0;
		}
		else if (*v.token == '>')
		{
			cmd = redir_cmd(cmd, v.quote, v.end_quote, O_WRONLY | O_CREAT);
			((t_redir_cmd *)cmd)->fd = 1;
		}
		else if (*v.token == '+') // '+' is a special case. check the video. >>
		{
			cmd = redir_cmd(cmd, v.quote, v.end_quote, O_WRONLY | O_CREAT);
			((t_redir_cmd *)cmd)->fd = 1;
		}
	}
	return (cmd);
}
