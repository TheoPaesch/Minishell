/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:22:28 by mstrauss          #+#    #+#             */
/*   Updated: 2023/11/16 22:39:43 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief locates the first occurrence of c (as an unsigned char) in string s
/// @param s string to be searched in
/// @param c character to find
/// @param n amount of bytes to search
/// @return a pointer to the byte located,
///			or NULL if no such byte exists within n bytes
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	d;
	unsigned char	*ss;
	unsigned long	i;

	d = (unsigned char)c;
	i = 0;
	ss = (unsigned char *)s;
	while (i < n)
	{
		if (ss[i] == d)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
