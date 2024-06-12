/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:00:02 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/12 12:34:15 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef LIBFT_H
#  include "libft.h"
# endif
# include <curses.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <term.h>
# include <unistd.h>

/* -------------------------- Command / token type -------------------------- */
# define EXEC 1
# define REDIR 2
# define PIPE 3
# define LIST 4
# define BACK 5

/* -------------------------------------------------------------------------- */
/*                                   STRUCTS                                  */
/* -------------------------------------------------------------------------- */

# define MAXARGS 50

typedef struct s_token
{
	char		*token;
}				t_token;

typedef struct s_env
{
	char		*key;
	char		*value;
}				t_env;

typedef struct s_program
{
	t_list		*env;
	t_list		*expo;
	t_list		*mem;
	bool		ex_status;
	bool		isatty;
}				t_program;

typedef struct s_cmd
{
	int			type;
}				t_cmd;

typedef struct s_exec_cmd
{
	int			type;

	char		*argv[MAXARGS];
	char		*end_argv[MAXARGS];
}				t_exec_cmd;

typedef struct s_redir_cmd
{
	int			type;
	t_cmd		*cmd;
	char		*file;
	char		*end_file;
	int			mode;
	int			fd;
}				t_redir_cmd;

typedef struct s_pipe_cmd
{
	int			type;
	t_cmd		*left;
	t_cmd		*right;
}				t_pipe_cmd;

typedef struct s_list_cmd
{
	int			type;
	t_cmd		*left;
	t_cmd		*right;
}				t_list_cmd;

typedef struct s_back_cmd
{
	int			type;
	t_cmd		*cmd;
}				t_back_cmd;

/* --------------------------------- Helpers -------------------------------- */

typedef struct s_parse_exec_vars
{
	t_cmd		*retrn_val;
	t_exec_cmd	*cmd;
	int			token;
	int			argc;
	char		*quote;
	char		*end_quote;
}				t_parse_exec_vars;

typedef struct s_parse_redir_vars
{
	int			token;
	char		*quote;
	char		*end_quote;
}				t_parse_redir_vars;

/* -------------------------------------------------------------------------- */
/*                                  FUNCTIONS                                 */
/* -------------------------------------------------------------------------- */
void			splash_screen(void);

void			handle_sigint(int sig);

/* ---------------------------------- Pipes --------------------------------- */
void			safe_pipe(int pipefd[2]);
pid_t			safe_fork(void);

/* -------------------------------- Get Input ------------------------------- */
void			empty_env(void);
void			get_input(char **envp, t_list **env, t_list **expo);
void			fill_program(t_program *shell, char **envp);

/* ---------------------------- Memory Management --------------------------- */
void			ms_exit(t_program *shell);

/* -------------------------------- Execution ------------------------------- */
t_list			*pre_pointer(t_list *env, char *key);
void			change_value_both(t_list *expo, t_list *env, char *key,
					char *value);
void			print_export(t_list *expo);
void			print_env(t_list *env);
void			add_env(t_list *env, char *key, char *value);
void			add_export(t_list *env, t_list *expo, char *key, char *value);
void			exec_exec(t_cmd *cmd);
void			exec_redir(t_cmd *cmd);
void			exec_list(t_cmd *cmd);
void			exec_pipe(t_cmd *cmd);
void			exec_back(t_cmd *cmd);

/* ------------------------- Join Commands and ARGs ------------------------- */

/* ------------------------------ Tokenization ------------------------------ */
int				get_token(char **ptr_str, char *end_str, char **quote,
					char **end_quote);
char			*ft_strtok(char *str, const char *delimiters);

/* --------------------------------- Parsing -------------------------------- */
int				scan_skip_ws(char **ptr_str, char *end_str, char *tokens);
t_cmd			*parse_block(char **ptr_str, char *end_str);
t_cmd			*parse_line(char **ptr_str, char *end_str);
t_cmd			*parse_pipe(char **ptr_str, char *end_str);
t_cmd			*parse_redir(t_cmd *cmd, char **ptr_str, char *end_str);
t_cmd			*parse_cmd(char *str);
t_cmd			*parse_exec(char **ptr_str, char *end_str);

t_cmd			*nullterm(t_cmd *cmd);
t_cmd			*null_exec_cmd(t_cmd *cmd);
t_cmd			*null_redir(t_cmd *cmd);
t_cmd			*null_pipe(t_cmd *cmd);
t_cmd			*null_list(t_cmd *cmd);
t_cmd			*null_back(t_cmd *cmd);

t_cmd			*exec_cmd(void);
t_cmd			*redir_cmd(t_cmd *sub_cmd, char *file, char *end_file,
					int mode);
t_cmd			*pipe_cmd(t_cmd *left, t_cmd *right);
t_cmd			*list_cmd(t_cmd *left, t_cmd *right);
t_cmd			*back_cmd(t_cmd *sub_cmd);

char			*read_input(t_program *mushell);

#endif