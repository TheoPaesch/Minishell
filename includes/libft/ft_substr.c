/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:45:42 by mstrauss          #+#    #+#             */
/*   Updated: 2023/11/17 00:16:03 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Allocates (with malloc(3)) and returns a substring from the string s.
///			The substring begins at index ’start’ and is of maximum size ’len’.
/// @param s 		The string from which to create the substring.
/// @param start 	The start index of the substring in the string ’s’.
/// @param len 		The maximum length of the substring.
/// @return			The substring. NULL if the allocation fails.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned long	s_len;

	s_len = ft_strlen(s);
	if ((len == 0 || s_len == 0) || start >= s_len)
	{
		dst = malloc(1);
		if (dst == NULL)
			return (NULL);
		*dst = '\0';
		return (dst);
	}
	else if (len > s_len - start)
	{
		dst = malloc(s_len - start + 1);
		if (dst == NULL)
			return (NULL);
		len = s_len;
	}
	else
		dst = malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, &s[start], len + 1);
	return (dst);
}
