/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:05:13 by mstrauss          #+#    #+#             */
/*   Updated: 2023/11/17 00:12:06 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 	Locates the FIRST occurrence of c (as a char)
///			in the string pointed to by s.
///			The terminating null character is considered to be part of the str
///			therefore if c is `\0', the functions locate the terminating `\0'
/// @param s	string to be searched.
/// @param c	character to search for.
/// @return		pointer to the located character, NULL if non found
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	c = (char)c;
	while (s[++i] != '\0')
		if (s[i] == c)
			return ((char *)&s[i]);
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
