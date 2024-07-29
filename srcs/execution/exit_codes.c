/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_codes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:02:32 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/27 17:44:02 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// if its bigger than 255, then the exit code = code % 256
// if it is negative 				exit code = 256 + (-)code
int	calc_exit_code(int code)
{
	if (code < 0)
		return (256 + code);
	else if (code > 255)
		return (code % 256);
	else
		return (code);
}
