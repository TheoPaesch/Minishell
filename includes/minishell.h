/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:00:02 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/08 15:18:26 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# ifndef LIBFT_H
#  include "libft.h"
# endif
# include <curses.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
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

#

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
	int			ex_status;
	bool		isatty;
	bool		is_dbg;
	int			last_exit_code;
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
char			*get_path(char *executable);
int				get_token(char **ptr_str, char *end_str, char **quote,
					char **end_quote);
t_program		*get_shell(void);
t_program		*init_global(t_program *shell);
void			handle_sigint(int sig);
void			splash_screen(t_program *shell);
bool			check_key(t_list *tmp, char *key);
void			change_value_both(t_list *expo, t_list *env, char *key,
					char *value);
void			update_dir(t_list *env, t_list *expo);

/* -------------------------------- Builtins -------------------------------- */
int				cd_builtin(t_cmd *cmd);
void			print_env(t_list *env);
void			print_export(t_list *expo);
int				echo_builtin(t_cmd *cmd);
void			ms_exit(t_program *shell);
int				unset_builtin(t_cmd *cmd);
void			unset_one(t_list *env, t_list *expo, char *key);
int				export_builtin(t_cmd *cmd);
int				env_builtin(t_cmd *cmd);
void			exit_builtin(t_cmd *cmd);
int				pwd_builtin(t_cmd *cmd);

/* -------------------------------- Expander -------------------------------- */
int				check_valid_quotes(char *str);
// move to lexer?
void			expand(t_exec_cmd *exec_cmd);
char			*expand_exit_stat(void);
char			*expand_var(char *str);
char			*get_value_of_key(t_list *lst, char *key);

/* ----------------------------- Error Handling ----------------------------- */
// void			ft_panic(char *err_msg, int exit_stat);
// void			ft_set_errno(int exit_stat);

/* ---------------------------------- Pipes --------------------------------- */
void			exec_pipe_left(pid_t pid, int (*pipes)[2], t_pipe_cmd *p_cmd);
void			exec_pipe_right(pid_t pid, int (*pipes)[2], t_pipe_cmd *p_cmd);
pid_t			safe_fork(void);
void			safe_pipe(int pipefd[2]);

/* -------------------------------- Get Input ------------------------------- */
void			empty_env(void);
void			fill_program(t_program *shell, char **envp);
void			get_input(char **envp, t_list **env, t_list **expo);
char			*get_value(char *str);
char			*get_key(char *str);

/* ---------------------------- Memory Management --------------------------- */
t_list			**init_mem_man(t_list **shell_mem);
t_list			**get_mem_lst(void);
t_list			*new_list(void);

/* -------------------------------- Execution ------------------------------- */
void			add_env(t_list *env, char *key, char *value);
void			add_export(t_list **env, t_list **expo, char *key, char *value);
void			change_value_both(t_list *expo, t_list *env, char *key,
					char *value);
void			exec_builtin(t_cmd *cmd);
void			exec_exec(t_cmd *cmd);
void			exec_redir(t_cmd *cmd);
void			exec_list(t_cmd *cmd);
void			exec_pipe(t_cmd *cmd);
void			exec_back(t_cmd *cmd);
void			execute_cmd(t_cmd *cmd);
int				is_builtin(t_exec_cmd *exec_cmd);
t_list			*pre_pointer(t_list *env, char *key);

/* ------------------------- Join Commands and ARGs ------------------------- */

/* ------------------------------ Tokenization ------------------------------ */
int				get_token(char **ptr_str, char *end_str, char **quote,
					char **end_quote);
// char			*ft_strtok(char *str, const char *delimiters);

/* --------------------------------- Parsing -------------------------------- */
t_cmd			*init_back_cmd(t_cmd *sub_cmd);
t_cmd			*list_cmd(t_cmd *left, t_cmd *right);
t_cmd			*init_exec_cmd(void);
t_cmd			*init_redir_cmd(t_cmd *sub_cmd, char *file, char *end_file,
					int mode);

t_cmd			*nullterm(t_cmd *cmd);
t_cmd			*null_exec_cmd(t_cmd *cmd);
t_cmd			*null_redir(t_cmd *cmd);
t_cmd			*null_pipe(t_cmd *cmd);
t_cmd			*null_list(t_cmd *cmd);
t_cmd			*null_back(t_cmd *cmd);

t_cmd			*parse_block(char **ptr_str, char *end_str);
t_cmd			*parse_line(char **ptr_str, char *end_str);
t_cmd			*parse_pipe(char **ptr_str, char *end_str);
t_cmd			*parse_redir(t_cmd *cmd, char **ptr_str, char *end_str);
t_cmd			*parse_cmd(char *str);
t_cmd			*parse_exec(char **ptr_str, char *end_str);
t_cmd			*pipe_cmd(t_cmd *left, t_cmd *right);

char			*read_input(t_program *mushell);
int				scan_skip_ws(char **ptr_str, char *end_str, char *tokens);

#endif