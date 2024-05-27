/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:01:15 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/27 14:56:37 by tpaesch          ###   ########.fr       */
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
char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	i;
	unsigned long	j;
	char			*ptr;

	i = -1;
	j = -1;
	ptr = NULL;
	if (ft_malloc(ptr, ft_strlen(s1) + ft_strlen(s2) + 1))
		exit(1);
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[++j])
		ptr[i + j] = s2[j];
	ptr[i + j] = '\0';
	return (ptr);
}
