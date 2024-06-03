/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:00:02 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/03 19:33:47 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef LIBFT_H
#  include "libft.h"
# endif
# include <curses.h>
# include <errno.h> // genug und ich brauche nicht 10 files oeffnen
# include <fcntl.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
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

# define MAXARGS 10

typedef struct s_token
{
	char		*token;
}				t_token;

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
	struct cmd	*cmd;
	char		*file;
	char		*end_file;
	int			mode;
	int			fd;
}				t_redir_cmd;

typedef struct s_pipe_cmd
{
	int			type;
	struct cmd	*left;
	struct cmd	*right;
}				t_pipe_cmd;

typedef struct s_list_cmd
{
	int			type;
	struct cmd	*left;
	struct cmd	*right;
}				t_list_cmd;

typedef struct s_back_cmd
{
	int			type;
	struct cmd	*cmd;
}				t_back_cmd;

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
	int			*token;
	char		*quote;
	char		*end_quote;
}				t_parse_redir_vars;

/* -------------------------------------------------------------------------- */
/*                                  FUNCTIONS                                 */
/* -------------------------------------------------------------------------- */

void			splash_screen(void);

/* ---------------------------------- Pipes --------------------------------- */

/* -------------------------------- Get Input ------------------------------- */

/* ---------------------------- Memory Management --------------------------- */

typedef struct s_mem
{
	void		**ext_ptr;
	void		*allocd_mem;
}				t_mem;

void			ft_free(void **ptr);
int				ft_malloc(void *ptr, size_t size);
void			ft_del_mem(t_mem *mem);

/* -------------------------------- Execution ------------------------------- */

/* ------------------------- Join Commands and ARGs ------------------------- */

/* ------------------------------ Tokenization ------------------------------ */

char			*ft_strtok(char *str, const char *delimiters);

/* --------------------------------- Parsing -------------------------------- */

size_t			ft_strspn(const char *str1, const char *str2);
char			*ft_strjoinall(int count, bool free, ...);
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
t_cmd			*null_pipe(t_pipe_cmd *cmd);
t_cmd			*null_list(t_cmd *cmd);
t_cmd			*null_back(t_cmd *cmd);

t_cmd			*exec_cmd(void);
t_cmd			*redir_cmd(t_cmd *sub_cmd, char *file, char *end_file,
					int mode);
t_cmd			*pipe_cmd(t_cmd *left, t_cmd *right);
t_cmd			*list_cmd(t_cmd *left, t_cmd *right);
t_cmd			*back_cmd(t_cmd *sub_cmd);

#endif