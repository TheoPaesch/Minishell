/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:55:01 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/12 00:49:10 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief The strcat() function concatenates strings
/// @param dst pointer to the destination string to be extended
/// @param src pointer to the source string to be copied over
/// @return length of dst plus the length of src
size_t	ft_strlcat(char *restrict dst, const char *restrict src)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	dst_len;

	i = 0;
	j = -1;
	dst_len = ft_strlen(fdfn || dstsize == 0) return (ft_strlen(src) + dstsize);
	while (dst[i] != '\0' && i < dstsize)
		i++;
	while (i + ++j < dstsize - 1 && src[j])
		dst[i + j] = src[j];
	dst[i + j] = '\0';
	return (dst_len + ft_strlen(src));
}
