/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/07/29 19:20:24 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifdef DEBUG
#  define DEBUG_FLAG true
# else
#  define DEBUG_FLAG false
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
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>
# include <unistd.h>

/* ------------------------------- Shell Name ------------------------------- */

# define NAME bash

/* -------------------------- Command / token type -------------------------- */
# define EXEC 1
# define REDIR 2
# define PIPE 3
# define LIST 4
# define BACK 5

/* -------------------------------------------------------------------------- */
/*                                   STRUCTS                                  */
/* -------------------------------------------------------------------------- */

# define MAXARGS 255
# define MAX_STR_LEN 2048

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
	int			last_exit_code;
	int			orig_stdin;
	int			orig_stdout;
	bool		isatty;
	bool		is_dbg;
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
	char		*quote;
	char		*end_quote;
	int			type;
	int			argc;
}				t_parse_exec_vars;

typedef struct s_parse_redir_vars
{
	char		*quote;
	char		*end_quote;
	int			type;
}				t_parse_redir_vars;

typedef struct s_heredoc
{
	char		*delim;
	char		*full_arg;
	char		*out;
	char		*file;
	int			size;
}				t_heredoc;

/* ---------------------------------- DEBUG --------------------------------- */
t_cmd			*print_tree(t_cmd *root);
t_cmd			*print_tree_util(t_cmd *node, int space);
void			process_and_print_node(t_cmd *node, int space);
void			print_spaces(int space);
const char		*get_node_type_str(int type);

/* -------------------------------------------------------------------------- */
/*                                  FUNCTIONS                                 */
/* -------------------------------------------------------------------------- */
char			*get_path(char *executable);
char			*path_cwd_fallback(char *executable);
int				get_token(char **ptr_str, char *end_str, char **quote,
					char **end_quote);
t_program		*get_shell(void);
t_program		*init_global(t_program *shell);
void			handle_sigint(int sig);
void			splash_screen(t_program *shell);
bool			check_key(t_list *tmp, char *key);
void			update_dir(t_list **env, t_list **expo, char *new, char *old);
void			restore_fds(t_program *shell);

/* --------------------------------- Quotes --------------------------------- */
void			gt_handle_quote(char **tmp, char *end_str, int *return_val);
void			gt_handle_redir(char **tmp, int *return_val);
char			*parse_quotes(char **quote, char **end_quote, int *type);

/* -------------------------------- Builtins -------------------------------- */
int				cd_builtin(t_cmd *cmd);
void			print_env(t_list *env);
void			print_export(t_list *expo);
int				echo_builtin(t_cmd *cmd);
void			ms_exit(int code);
int				unset_builtin(t_cmd *cmd);
void			unset_both(t_list **env, t_list **expo, char *key);
void			unset_one(t_list **lst, char *key);
int				unset_verify_key(char *key);
int				export_builtin(t_cmd *cmd);
int				expo_verify_arg(char *arg);
int				env_builtin(t_cmd *cmd);
int				exit_builtin(t_cmd *cmd);
int				errno_to_exitcode(int err);
int				calc_exit_code(int code);
int				pwd_builtin(t_cmd *cmd);

/* -------------------------------- Heredoc --------------------------------- */
char			*arg_check(char *eof, t_heredoc *hrdc);
int				def_arg_len(char *eof, t_heredoc *hrdc);
char			*in_none(char *input, int len);
void			heredoc_loop(t_heredoc *hrdc);
void			get_txt(t_heredoc *hrdc);
bool			hrdc_line_check(char *line, t_heredoc *hrdc);
char			*heredoc_base(char *input);
int				len_adjust(char *eof, t_heredoc *hrdc);
bool			heredoc_placement(char *input, int *i, t_heredoc *hrdc);
char			*fill_out(char *out, int i, char *input, t_heredoc *hrdc);
int				in_quotes(char *input);
bool			count_in_single(char *eof, int *i, int *amount);
bool			count_in_double(char *eof, int *i, int *amount);
int				output_quotes(char *input, char *output);

/* -------------------------------- Expander -------------------------------- */
int				check_valid_quotes(char *str);
// move to lexer?
void			expand(t_exec_cmd *exec_cmd);
char			*expand_tilde(char **ptr);
char			*expand_exit_stat(void);
char			*expand_var(char **str);
char			*expand_word(char **start, char **end, int *type);
char			*get_value_of_key(t_list *lst, char *key);
char			*early_expand(char *input);
void			copy_through_pair(char **output, char **input, char sym);

/* ----------------------------- Error Handling ----------------------------- */
void			set_exit_code(int status);
void			print_err(char *str);
// void			ft_panic(char *err_msg, int exit_stat);
// void			ft_set_errno(int exit_stat);
void			p_err(int i);

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
void			add_env(t_list **env, char *key, char *value);
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