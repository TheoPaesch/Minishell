/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:01:15 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/14 18:05:50 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief 		Allocates (with malloc(3)) and returns a new
///				string, which is the result of the concatenation
///				of ’s1’ and ’s2’.
/// @param s1 	String 1
/// @param s2 	String 2
/// @return 	New composite String
///				NULL if the allocation fails.
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	size;

	if (!s1)
		return (NULL);
	if (!s2)
		return ((char *)s1);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = ft_malloc(sizeof(char) * size);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, size);
	ft_strlcat(ret, s2, size);
	return (ret);
}
