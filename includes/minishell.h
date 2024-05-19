/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:00:02 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/19 15:39:41 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "enviroment/env.h"
# include "libft.h"
# include "signal/sig_handl.h"
# include <stdbool.h>
# include <stdio.h>
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

/* -------------------------------- Execution ------------------------------- */

void		print_export(t_list *expo);
void		prtint_env(t_list *env);
void		add_export(t_list *env, t_list *expo, char *key, char *value);

/* ------------------------- Join Commands and ARGs ------------------------- */

/* ------------------------------ Tokenization ------------------------------ */

/* --------------------------------- Parsing -------------------------------- */

#endif
