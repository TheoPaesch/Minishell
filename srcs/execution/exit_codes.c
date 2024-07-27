/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_codes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:02:32 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/27 14:20:52 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	calc_exit_code(int code)
{
	if (code < 0)
		return (255 - code);
	else if (code > 255)
		return (code % 256);
	else
		return (code);
}
