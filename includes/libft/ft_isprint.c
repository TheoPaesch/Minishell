/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:39:18 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/12 18:25:05 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief checks if a character is in the printable ascii range
/// @param c character to be checked
/// @return 1 if printable, 0 if non-printable
int	ft_isprint_no_space(int c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}
