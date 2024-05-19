/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:00:02 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/19 16:17:42 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef LIBFT_H
#  include "libft.h"
# endif
# include "enviroment/env.h"   // koennen wir die yeeten?
# include "signal/sig_handl.h" // bitte ALLES in minishell.h, ist uebersichtlich
# include <errno.h>            // genug und ich brauche nicht 10 files oeffnen
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/* -------------------------------------------------------------------------- */
/*                                   STRUCTS                                  */
/* -------------------------------------------------------------------------- */
typedef struct s_token
{
	char	*token;
}			t_token;

typedef struct s_env
{
	char	*key;
	char	*value;
}			t_env;

/* -------------------------------------------------------------------------- */
/*                                  FUNCTIONS                                 */
/* -------------------------------------------------------------------------- */

/* ---------------------------------- Pipes --------------------------------- */

/* -------------------------------- Get Input ------------------------------- */

void		ft_epmty_env(void);
void		ft_get_input(char **envp);

/* ---------------------------- Memory Management --------------------------- */
typedef struct s_mem
{
	void	**ext_ptr;
	void	*allocd_mem;
}			t_mem;

void		ft_free(void **ptr);
void		*ft_malloc(void **ptr, int size);
void		ft_del_mem(t_mem *mem);

/* -------------------------------- Execution ------------------------------- */

void		print_export(t_list *expo);
void		prtint_env(t_list *env);
void		add_export(t_list *env, t_list *expo, char *key, char *value);

/* ------------------------- Join Commands and ARGs ------------------------- */

/* ------------------------------ Tokenization ------------------------------ */
char		*ft_strtok(char *str, const char *delimiters);

/* --------------------------------- Parsing -------------------------------- */
size_t		ft_strspn(const char *str1, const char *str2);
char		*ft_strjoinall(int count, bool free, ...);

#endif
