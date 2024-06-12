/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:27:05 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/12 12:28:57 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief 	strcmp() lexicographically compares
///			the null-terminated strings s1 and s2.
/// @param s1 String 1
/// @param s2 String 2
/// @return integer greater than, equal to, or less than 0,
/// 		according as the string s1 is greater than, equal to, or less than
/// 		the string s2.
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
