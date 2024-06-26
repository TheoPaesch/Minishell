/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:03:28 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/11 19:13:20 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Converts an alphabetic character from capital to lower case
/// @param c Character to convert
/// @return Converted character if successful
///			unconverted character if char is not alphabetical
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
