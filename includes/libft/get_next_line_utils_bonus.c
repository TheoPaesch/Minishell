/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 00:25:05 by mstrauss          #+#    #+#             */
/*   Updated: 2023/12/14 21:05:36 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 	strlcpy() copies up to dstsize - 1 characters from the string src to
/// 		dst, NUL-terminating the result if dstsize is not 0.
/// @param dst			destination string
/// @param src			source string
/// @param dstsize		size of dst INCLUDING Nul-termination
/// @return				length of source
size_t	gnl_strlcpy(char *dst, char *src, size_t dstsize)
{
	unsigned long	i;

	i = 0;
	if (dstsize == 0)
		return (gnl_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (gnl_strlen(src));
}

/// @brief 		Allocates (with malloc(3)) and returns a new
///				string, which is the result of the concatenation
///				of ’s1’ and ’s2’.
/// @param s1 	String 1
/// @param s2 	String 2
/// @return 	New composite String
///				NULL if the allocation fails.
char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = -1;
	j = -1;
	if (s1 == NULL)
		return (free(s2), NULL);
	ptr = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (ptr == NULL)
		return (free(s1), NULL);
	while (s1 && s1[++i])
		ptr[i] = s1[i];
	while (s2 && s2[++j])
		ptr[i + j] = s2[j];
	ptr[i + j] = '\0';
	free(s1);
	s1 = NULL;
	return (ptr);
}

/// @brief 		Allocates sufficient memory for a copy of the string s1,
/// 			does the copy, and returns a pointer to it.
/// @param s1 	String 1.
/// @return 	Pointer to allocated memory.
///				if fail; return NULL and set errno to ENOMEM.
char	*gnl_strdup(char *s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = gnl_strlen(s1);
	i = -1;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (++i <= len && s1[i])
		ptr[i] = s1[i];
	ptr[i] = '\0';
	return (ptr);
}

/// @brief 	Locates the FIRST occurrence of c (as a char)
///			in the string pointed to by s.
///			The terminating null character is considered to be part of the str
///			therefore if c is `\0', the functions locate the terminating `\0'
/// @param s	string to be searched.
/// @param c	character to search for.
/// @return		pointer to the located character, NULL if non found
int	gnl_strchr(char *s, int c)
{
	int	i;

	if (s == NULL)
		return (0);
	i = -1;
	c = (char)c;
	if (s == NULL)
		return (0);
	while (s[++i] != '\0')
		if (s[i] == c)
			return (i);
	return (-1);
}

/// @brief Contiguously allocates enough space for count objects
///			that are size bytes of memory filled with bytes of value zero
/// @param count amount of objects
/// @param size bytesize of an object
/// @return If successful calloc returns a pointer to allocated memory.
/// If there is an error, they return a NULL pointer and set errno to ENOMEM.
void	*gnl_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	unsigned long	i;
	int				n;

	i = 0;
	n = count * size;
	ptr = NULL;
	ptr = malloc(n);
	if (ptr == NULL)
		return (NULL);
	while (0 < n)
		ptr[n-- - 1] = 0;
	return (ptr);
}
