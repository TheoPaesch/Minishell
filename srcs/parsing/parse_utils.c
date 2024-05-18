/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:49:50 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/18 17:23:27 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

const static char	*g_whitespace = " \t\r\n\v ";
const static char	*g_symbols = "<|>&;()";

struct cmd	*parse_cmd(char *str)
{
	char		*end_str;
	struct cmd	*cmd;

	end_str = str + ft_strlen(str);
	cmd = parse_line(&str, end_str);
	scan_skip_ws(&str, end_str, "");
	if (str != end_str)
	{
		printf(2, "Leftovers: %s\n", str); // remove later
		error();                           // add error function
	}
}
//

struct cmd			*parse_exec(char **ptr_str, char *end_str);

struct cmd			*parse_redir(char **ptr_str, char *end_str);

struct cmd	*parse_pipe(char **ptr_str, char *end_str)
{
	struct cmd	*cmd;

	cmd = parse_exec(ptr_str, end_str);
	if (scan_skip_ws(ptr_str, end_str, "|"))
	{
		get_token(ptr_str, end_str, 0, 0);
		cmd = pipe_cmd(cmd, parse_pipe(ptr_str, end_str));
	}
	return (cmd);
}

struct cmd	*parse_line(char **ptr_str, char *end_str)
{
	struct cmd	*cmd;

	cmd = parse_pipe(ptr_str, end_str);
	while (scan_skip_ws(ptr_str, end_str, "&"))
	{
		get_token(ptr_str, end_str, 0, 0); // adjust after writing get_token()
		cmd = back_cmd(cmd);               // adjust after writing back_cmd()
	}
	if (scan_skip_ws(ptr_str, end_str, ";"))
	{
		get_token(ptr_str, end_str, 0, 0);
		cmd = listcmd(cmd, parse_line(ptr_str, end_str));
	}
	return (cmd);
}

struct cmd			parse_block(void);

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
