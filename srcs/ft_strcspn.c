/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:47:55 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/17 16:07:54 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Scans str1 for the first occurrence of any of the characters that are
/// part of str2,returning the number of characters of str1 read before this
/// first occurrence. The search includes the terminating null-characters.
/// Therefore,the function will return the length of str1 if none of the
/// characters of str2 are found in str1.
/// @param str1 C string to be scanned.
/// @param str2 C string containing the characters to match.
/// @return The length of the initial part of str1 not containing any of the
/// characters that are part of str2. This is the length of str1 if none of the
/// characters in str2 are found in str1.
size_t	ft_strcspn(const char *str1, const char *str2)
{
	int	i;
	int	j;

	if (!str1 || !str2)
		return (0);
	i = 0;
	j = 0;
	while (str1[i])
	{
		while (str2[j])
		{
			if (str1[i] == str2[j])
				return (i + 1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
