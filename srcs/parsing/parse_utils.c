/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:49:50 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/03 20:24:48 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ToDo:
- nullterm()
- get_token()
- error()

*/

#include "../../includes/minishell.h"

static const char	*g_whitespace = " \t\r\n\v ";
// static const char	*g_symbols = "<|>&;()";

/*
STILL MISSING OPERATORS:

<<	should be given a delimiter, then read the input until a line containing the
	delimiter is seen. However, it doesn’t have to update the history!

>>	redirect output in append mode.

'	single quote which should prevent the shell from interpreting the
	metacharacters in the quoted sequence.


UNSURE:

is $ sign interpreting available inside of ""?
*/

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

t_cmd	*parse_line(char **ptr_str, char *end_str)
{
	t_cmd	*cmd;

	cmd = parse_pipe(ptr_str, end_str);
	while (scan_skip_ws(ptr_str, end_str, "&"))
	{
		get_token(ptr_str, end_str, 0, 0); // adjust after writing get_token()
		cmd = back_cmd(cmd);               // adjust after writing back_cmd()
	}
	if (scan_skip_ws(ptr_str, end_str, ";"))
	{
		get_token(ptr_str, end_str, 0, 0);
		cmd = list_cmd(cmd, parse_line(ptr_str, end_str));
	}
	return (cmd);
}

t_cmd	*parse_block(char **ptr_str, char *end_str)
{
	t_cmd	*cmd;

	if (!scan_skip_ws(ptr_str, end_str, "("))
		strerror(1); // adjust for real error func
	get_token(ptr_str, end_str, 0, 0);
	cmd = parse_line(ptr_str, end_str);
	if (!scan_skip_ws(ptr_str, end_str, ")"))
		strerror(1); // SYNTAX: missing an ')'"
	get_token(ptr_str, end_str, 0, 0);
	cmd = parse_redir(cmd, ptr_str, end_str);
	return (cmd);
}

int	scan_skip_ws(char **ptr_str, char *end_str, char *tokens)
{
	char	*str;

	str = *ptr_str;
	while (str < end_str && ft_strchr(g_whitespace, *str))
		str++;
	*ptr_str = str;
	if (*str && ft_strchr(tokens, *str))
		return (true);
	else
		return (false);
}
