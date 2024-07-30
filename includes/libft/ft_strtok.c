/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:51:09 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/30 20:31:22 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief A sequence of calls to this function split str into tokens,
/// which are sequences of contiguous characters separated by
/// any of the characters that are part of delimiters.
/// @param str C string to truncate.
///             Notice that this string is modified by being broken into smaller
///             strings (tokens). Alternatively,a null pointer may be specified,
///             in which case the function continues scanning where a previous
///             successful call to the function ended.
/// @param delimiters C string containing the delimiter characters.
///                     These can be different from one call to another.
/// @return     The beginning of the next token in the str.
char	*ft_strtok(char *str, const char *delimiters)
{
	static char	*next;
	char		*current;

	if (str != NULL)
		next = str;
	if (next == NULL)
		return (NULL);
	next += ft_strspn(next, delimiters);
	if (*next == '\0')
		return (next = NULL);
	current = next;
	next += ft_strcspn(next, delimiters);
	if (*next != '\0')
	{
		*next = '\0';
		next++;
	}
	return (current);
}
