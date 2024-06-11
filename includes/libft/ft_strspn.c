/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:50:46 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/12 00:40:32 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Returns the length of the initial portion of str1 which consists only
/// of characters that are part of str2. The search does not include the
/// terminating null-characters of either strings, but ends there.
/// @param str1 C string to be scanned.
/// @param str2 C string containing the characters to match.
/// @return The length of the initial part of str1 not containing any of the
/// characters that are part of str2. This is the length of str1 if none of the
/// characters in str2 are found in str1
size_t	ft_strspn(const char *str1, const char *str2)
{
	int	i;
	int	j;

	if (!str1 || !str2)
		return (0);
	i = 0;
	while (str1[i])
	{
		j = 0;
		while (str2[j])
		{
			if (str1[i] == str2[j])
				break ;
			j++;
		}
		if (!str2[j])
			return (i);
		i++;
	}
	return (i);
}
