/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:37 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/14 20:24:00 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minishell.h"

int	main(int ac, char **av, char **env)
{
	if (ac > 1)
	{
		ft_putstr("minishell: ");
		ft_putstr("no arguments needed\n");
	}
	else if (ac == 1 && av[1] != NULL)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGINT, SIG_IGN);
		ft_get_input(env);
	}
}
