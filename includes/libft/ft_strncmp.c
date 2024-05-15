/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:12:38 by mstrauss          #+#    #+#             */
/*   Updated: 2023/11/17 00:01:45 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 	strncmp() lexicographically compares
///			the null-terminated strings s1 and s2.
/// @param s1 String 1
/// @param s2 String 2
/// @param n Amount of characters to compare
/// @return integer greater than, equal to, or less than 0,
/// 		according as the string s1 is greater than, equal to, or less than
/// 		the string s2.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && i < n && s1[i] && s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
