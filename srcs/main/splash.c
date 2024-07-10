/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:15:58 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/09 19:58:18 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	splash_screen(t_program *shell)
{
	(void)shell;
	if (!isatty(fileno(stdin)))
		return ;
	printf("\033[0;33m  ,ggg, ,ggg,_,ggg,                                  \
                                   _.-''|''-._          \033[0m\n");
	printf("\033[0;33m dP\"\"Y8dP\"\"Y88P\"\"Y8b                        ,dP\
Yb,              ,dPYb, ,dPYb,        .-'     |     `-.       \033[0m\n");
	printf("\033[0;31m Yb, `88'  `88'  `88                        IP'`Yb   \
           IP'`Yb IP'`Yb    .'   \\      |      /   `.   \033[0m\n");
	printf("\033[0;31m  `\"  88    88    88                        I8  8I  \
            I8  8I I8  8I    \\     \\     |     /     /   \033[0m\n");
	printf("\033[0;35m      88    88    88                        I8  8'   \
           I8  8' I8  8'     `\\    \\    |    /    /'    \033[0m\n");
	printf("\033[0;35m      88    88    88  gg      gg    ,g,     I8 dPgg, \
   ,ggg,   I8 dP  I8 dP        `\\   \\   |   /   /'      \033[0m\n");
	printf("\033[0;34m      88    88    88  I8      8I   ,8'8,    I8dP\" \"\
8I  i8\" \"8i  I8dP   I8dP           `\\  \\  |  /  /'        \033[0m\n");
	printf("\033[0;34m      88    88    88  I8,    ,8I  ,8'  Yb   I8P    I8\
  I8, ,8I  I8P    I8P           _.-`\\ \\ | / /'-._       \033[0m\n");
	printf("\033[0;36m      88    88    Y8,,d8b,  ,d8b,,8'_   8) ,d8     I8\
, `YbadP' ,d8b,_ ,d8b,_        {_____`\\\\|//'_____}      \033[0m\n");
	printf("\033[0;36m      88    88    `Y88P'\"Y88P\"`Y8P' \"YY8P8P88P    \
 `Y8888P\"Y8888P'\"Y888P'\"Y88               `-'              \033[0m\n");
	printf("\n");
	printf("\033[0;36m                                             by\n");
	printf("                             Theo Paesch             Matthias \
	Strauss                                        \033[0m\n");
}
