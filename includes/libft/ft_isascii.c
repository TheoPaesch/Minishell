/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:36:24 by mstrauss          #+#    #+#             */
/*   Updated: 2023/10/11 17:34:40 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief 		Checks if character is in standard ASCII range
/// @param c 	Character to check
/// @return 	1 if true, 0 if false
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
