/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:55:53 by tpaesch           #+#    #+#             */
/*   Updated: 2024/07/01 15:08:03 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
@tpaesch
doesnt update $OLDPWD yet
*/
int	pwd_builtin(t_cmd *cmd)
{
	char	**args;
	char	*str;

	args = ((t_exec_cmd *)cmd)->argv;
	if (args[1] != NULL)
		return (printf("pwd does not allow options\n"), 1);
	str = getcwd(NULL, 0);
	if (!str)
		return (1);
	printf("%s\n", str);
	free(str);
	return (0);
}

/* just gewtcwd into str then free after*/

/* ---------------------------- UNSET TEST CASES ---------------------------- */

/*
unset

unset ""

unset =

unset "="

unset ""=

unset =""

unset ==

unset ?

unset "?"

unset $

unset "$"

unset $""

export TEST=100

unset doesntexist

unset OLDPWD

unset PATH

unset PATH

unset PATH

unset TES;T

unset TES.T

unset TES+T

unset TES=T

unset TES}T

unset TES{T

unset TES-T

unset -TEST

unset _TEST

unset TES_T

unset TEST_

unset TE*ST

unset TES#T

unset TES@T

unset TES!T

unset TES$?T

unset ============

unset +++++++

unset ________

unset export

unset echo

unset pwd

unset cd

unset unset

unset sudo

unset TES^T

unset TES!T

unset TES\~T

/bin/echo $HOME
unset $HOME
/bin/echo $HOME

/bin/echo $HOME
unset HOME
/bin/echo $HOME

/bin/echo $HOME
unset HOME
unset HOME
unset HOME
/bin/echo $HOME

/bin/echo $HOME
unset HOME
unset HOME
unset HOME
unset HOME
/bin/echo $HOME

*/