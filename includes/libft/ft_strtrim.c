/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:30:39 by mstrauss          #+#    #+#             */
/*   Updated: 2023/12/14 21:05:29 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_strtrim_end(char const *s1_end, char const *set)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	trim_end;

	i = 0;
	j = 0;
	trim_end = 0;
	while (set[j] && s1_end[i])
	{
		if (s1_end[i] == set[j])
		{
			trim_end++;
			i--;
			j = 0;
			continue ;
		}
		j++;
	}
	return (trim_end);
}

/// @brief 		Allocates (with malloc(3)) and returns a copy of
///				’s1’ with the characters specified in ’set’ removed
///				from the beginning and the end of the string.
/// @param s1 	String to be trimmed.
/// @param set 	The reference set of characters to trim.
/// @return 	Trimmed string.
///				NULL if the allocation fails.
char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	trim_beg;
	unsigned long	trim_end;

	i = 0;
	j = 0;
	trim_beg = 0;
	if (!*s1)
		return (ft_calloc(1, 1));
	while (set[j] && s1[i])
	{
		if (s1[i] == set[j])
		{
			trim_beg++;
			i++;
			j = 0;
			continue ;
		}
		j++;
	}
	trim_end = ft_strtrim_end(&s1[ft_strlen(s1) - 1], set);
	return (ft_substr(s1, trim_beg, ft_strlen(s1) - trim_beg - trim_end));
}
