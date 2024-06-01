/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:08:24 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/27 14:56:19 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief 		Allocates sufficient memory for a copy of the string s1,
/// 			does the copy, and returns a pointer to it.
/// @param s1 	String 1.
/// @return 	Pointer to allocated memory.
///				if fail; return NULL and set errno to ENOMEM.
char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen(s1) + 1;
	i = -1;
	ptr = NULL;
	if (ft_malloc(ptr, len))
		exit(1);
	while (++i <= len && s1[i])
		ptr[i] = s1[i];
	ptr[i] = '\0';
	return (ptr);
}
