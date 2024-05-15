/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:40:23 by mstrauss          #+#    #+#             */
/*   Updated: 2023/11/17 00:05:04 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Locates the first occurrence of the null-terminated
// string needle in the string haystack, where not more than len characters are
// searched. Characters that appear after a `\0' character are not searched.
/// @param haystack String to search in.
/// @param needle 	String to search for.
/// @param len		Amount of characters to search.
/// @return (If needle is an empty string,haystack is returned);
///	if needle occurs nowhere in haystack, NULL is returned;
/// otherwise a pointer to the first character of the first occurrence
/// of needle is returned.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned long	j;
	char			*ptr;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		ptr = (char *)&haystack[i];
		while (i + j <= len && haystack[i + j] == needle[j])
		{
			j++;
			if (!needle[j])
				return (ptr);
			if (i + j == len)
				return (NULL);
		}
		if (!needle[j])
			return (ptr);
		i++;
		j = 0;
	}
	return (NULL);
}
