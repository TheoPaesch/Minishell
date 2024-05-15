/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:52:52 by mstrauss          #+#    #+#             */
/*   Updated: 2023/11/17 00:12:24 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief locates the LAST occurrence of c (converted to a char) in the string
///			pointed to by s.
/// @param s String to search in
/// @param c Character to search for
/// @return	Pointer to the located character
///			NULL if the character does not appear in the string.
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) + 1;
	c = (char)c;
	while (--i >= 0)
		if (s[i] == c)
			return ((char *)&s[i]);
	return (NULL);
}
