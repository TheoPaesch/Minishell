/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:49:50 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/31 19:06:01 by mstrauss         ###   ########.fr       */
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

t_cmd	*parse_block(char **ptr_str, char *end_str)
{
	t_cmd	*cmd;

	if (!scan_skip_ws(ptr_str, end_str, "("))
		ft_debug_msg("expected '('\n");
	get_token(ptr_str, end_str, 0, 0);
	cmd = parse_line(ptr_str, end_str);
	if (!scan_skip_ws(ptr_str, end_str, ")"))
		ft_debug_msg("expected ')'\n");
	get_token(ptr_str, end_str, 0, 0);
	cmd = parse_redir(cmd, ptr_str, end_str);
	return (cmd);
}

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
