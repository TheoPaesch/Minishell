/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:00:02 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/10 20:39:20 by tpaesch          ###   ########.fr       */
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
	t_list				*mem;
	bool				ex_status;
	bool				isatty;
}						t_program;

/* -------------------------------------------------------------------------- */
/*                                  FUNCTIONS                                 */
/* -------------------------------------------------------------------------- */

/* ---------------------------------- Pipes --------------------------------- */

/* -------------------------------- Get Input ------------------------------- */

void					ft_empty_env(void);
void					ft_get_input(char **envp, t_list **env, t_list **expo);
void					fill_program(t_program *shell, char **envp);
t_list					*pre_pointer(t_list *env, char *key);
char					*get_value(char *str);
char					*get_key(char *str);

/* ---------------------------- Memory Management --------------------------- */

/* ------------------------------ Signal Handling --------------------------- */

void					handle_sigint(int sig);
/* -------------------------------- Execution ------------------------------- */

void					print_export(t_list *expo);
void					prtint_env(t_list *env);
void					add_export(t_list *env, t_list *expo, char *key,
							char *value);
void					add_env(t_list *env, char *key, char *value);
void					change_value_both(t_list *expo, t_list *env, char *key,
							char *value);
void					export_execution(t_list *env, t_list *expo, char *key,
							char *value);
bool					check_key(t_list *tmp, char *key);
void					cd(t_program *shell, char *path);
void					ms_exit(t_program *shell);

/* ------------------------- Join Commands and ARGs ------------------------- */

/* ------------------------------ Tokenization ------------------------------ */
char					*ft_strtok(char *str, const char *delimiters);

/* --------------------------------- Parsing -------------------------------- */
size_t					ft_strspn(const char *str1, const char *str2);
char					*ft_strjoinall(int count, bool free, ...);

char					*ft_read_input(t_program *mushell);

#endif
