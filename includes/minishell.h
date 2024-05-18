/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:00:02 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/18 15:54:21 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef LIBFT_H
#  include "libft.h"
# endif
# include "enviroment/env.h"   // koennen wir die yeeten?
# include "signal/sig_handl.h" // bitte ALLES in minishell.h, ist uebersichtlich
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

// char			whitespace[] = " \t\r\n\v";
// char			symbols[] = "<|>&;()";

/* -------------------------------------------------------------------------- */
/*                                   STRUCTS                                  */
/* -------------------------------------------------------------------------- */
typedef struct s_token
{
	char		*token;
}				t_token;

struct			cmd
{
	int			type;
};

struct			execcmd
{
	int			type;
	char		*argv[MAXARGS];
	char		*eargv[MAXARGS];
};

struct			redircmd
{
	int			type;
	struct cmd	*cmd;
	char		*file;
	char		*efile;
	int			mode;
	int			fd;
};

struct			pipecmd
{
	int			type;
	struct cmd	*left;
	struct cmd	*right;
};

struct			listcmd
{
	int			type;
	struct cmd	*left;
	struct cmd	*right;
};

struct			backcmd
{
	int			type;
	struct cmd	*cmd;
};
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
void			*ft_malloc(void **ptr, int size);
void			ft_del_mem(t_mem *mem);

/* -------------------------------- Execution ------------------------------- */

/* ------------------------- Join Commands and ARGs ------------------------- */

/* ------------------------------ Tokenization ------------------------------ */
char			*ft_strtok(char *str, const char *delimiters);

/* --------------------------------- Parsing -------------------------------- */
size_t			ft_strspn(const char *str1, const char *str2);
char			*ft_strjoinall(int count, bool free, ...);

#endif