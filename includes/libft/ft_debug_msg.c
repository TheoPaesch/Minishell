/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:26:05 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/23 17:26:06 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_debug_msg(char *msg)
{
	if (DEBUG_FLAG == true)
	{
		ft_putstr_fd("DEBUG: ", 2);
		ft_putstr_fd(msg, 2);
		ft_putchar_fd('\n', 2);
	}
}
