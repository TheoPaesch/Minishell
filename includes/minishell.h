/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:00:02 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/29 11:19:58 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <errno.h> 
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list	t_list;

/* -------------------------------------------------------------------------- */
/*                                   STRUCTS                                  */
/* -------------------------------------------------------------------------- */
typedef struct s_token
{
	char				*token;
}						t_token;

typedef struct s_env
{
	char				*key;
	char				*value;
}						t_env;

typedef struct s_program
{
	t_list				*env;
	t_list				*expo;
	bool				ex_status;
	bool				isatty;
}						t_program;

/* -------------------------------------------------------------------------- */
/*                                  FUNCTIONS                                 */
/* -------------------------------------------------------------------------- */

/* ---------------------------------- Pipes --------------------------------- */

/* -------------------------------- Get Input ------------------------------- */

void					ft_epmty_env(void);
void					ft_get_input(char **envp, t_list *env,
							t_list *expo);
void					fill_program(t_program *shell, char **envp);

/* ---------------------------- Memory Management --------------------------- */


/* ------------------------------ Signal Handling --------------------------- */

void					handle_sigint(int sig);
/* -------------------------------- Execution ------------------------------- */

void					print_export(t_list *expo);
void					prtint_env(t_list *env);
void					add_export(t_list *env, t_list *expo, char *key,
							char *value);

/* ------------------------- Join Commands and ARGs ------------------------- */

/* ------------------------------ Tokenization ------------------------------ */
char					*ft_strtok(char *str, const char *delimiters);

/* --------------------------------- Parsing -------------------------------- */
size_t					ft_strspn(const char *str1, const char *str2);
char					*ft_strjoinall(int count, bool free, ...);

char					*ft_read_input(t_program *mushell);

#endif
