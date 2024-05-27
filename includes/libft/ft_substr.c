/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:45:42 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/27 14:59:27 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
		dst = NULL;
		if (ft_malloc(dst, 1))
			exit(1);
		*dst = '\0';
		return (dst);
	}
	else if (len > s_len - start)
	{
		dst = NULL;
		if (ft_malloc(dst, s_len - start + 1))
			exit(1);
		len = s_len;
	}
	else
	{
		dst = NULL;
		if (ft_malloc(dst, len + 1))
			exit(1);
	}
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, &s[start], len + 1);
	return (dst);
}
