/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:08:24 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/14 18:04:16 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief 		Allocates sufficient memory for a copy of the string s1,
/// 			does the copy, and returns a pointer to it.
/// @param s1 	String 1.
/// @return 	Pointer to allocated memory.
///				if fail; return NULL and set errno to ENOMEM.
char	*ft_strdup(const char *str)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(str);
	ret = ft_malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, str, len + 1);
	return (ret);
}
