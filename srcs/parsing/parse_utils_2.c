/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:53:13 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/19 14:55:55 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

struct s_cmd	*parse_cmd(char *str)
{
	char			*end_str;
	struct s_cmd	*cmd;

	end_str = str + ft_strlen(str);
	cmd = parse_line(&str, end_str);
	scan_skip_ws(&str, end_str, "");
	if (str != end_str)
	{
		printf(2, "Leftovers: %s\n", str); // remove later
		error();                           // add error function
	}
	nullterm(cmd);
	return (cmd);
}

struct s_cmd	*parse_exec(char **ptr_str, char *end_str)
{
	struct s_cmd		*retrn_val;
	struct s_exec_cmd	*cmd;
	int					token;
	int					argc;
	char				*quote;
	char				*end_quote;

	if (scan_skip_ws(ptr_str, end_str, "("))
		return (parse_block(ptr_str, end_str));
	retrn_val = exec_cmd();
	cmd = (struct s_exec_cmd *)retrn_val;
	argc = 0;
	retrn_val = parse_redir(retrn_val, ptr_str, end_str);
	while (!scan_skip_ws(ptr_str, end_str, "|)&;"))
	{
		token = get_token(ptr_str, end_str, &quote, &end_quote);
		if (token == 0)
			break ;
		if (token != 'x')    // Return value if get_token does ???????
			error("SYNTAX"); // change once we have a error function
		cmd->argv[argc] = quote;
		cmd->end_argv[argc] = end_quote;
		argc++;
		if (argc >= MAXARGS)
			error("Amount of Arguments > MAXARGS");
				// change once we have a error function
		retrn_val = parse_redir(retrn_val, ptr_str, end_str);
	}
	cmd->argv[argc] = 0;
	cmd->end_argv[argc] = 0;
	return (retrn_val);
}

struct s_cmd	*parse_redir(struct s_cmd *cmd, char **ptr_str, char *end_str)
{
	int		*token;
	char	*quote;
	char	*end_quote;

	while (scan_skip_ws(ptr_str, end_str, "<>"))
	{
		token = get_token(ptr_str, end_str, 0, 0);
		if (get_token(ptr_str, end_str, &quote, &end_quote) != 'x')
			error("Can't redirect. File missing.");
		if (*token == '<')
			cmd = redir_cmd(cmd, quote, end_quote, O_RDONLY, 0);
		else if (*token == '>')
			cmd = redir_cmd(cmd, quote, end_quote, O_WRONLY | O_CREAT, 1);
		else if (*token == '+') // '+' is a special case. check the video
			cmd = redir_cmd(cmd, quote, end_quote, O_WRONLY | O_CREAT, 1);
	}
}
