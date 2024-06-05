/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:01:15 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/04 21:59:19 by tpaesch          ###   ########.fr       */
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
	size_t	len;

	if (!s1)
		return (NULL);
	if (!s2)
		return ((char *)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!ft_malloc(&ret, sizeof(char) * (len + 1)))
		exit(1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, len + 1);
	ft_strlcat(ret, s2, len + 1);
	return (ret);
}
