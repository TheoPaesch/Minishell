/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:09:58 by mstrauss          #+#    #+#             */
/*   Updated: 2023/11/16 23:50:45 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Determines char string length
/// @param s String to measure
/// @return Length of string including Nul-terminator
int	ft_strlen(const char *s)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
		;
	return (i);
}
