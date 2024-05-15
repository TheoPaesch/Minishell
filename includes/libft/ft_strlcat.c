/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:55:01 by mstrauss          #+#    #+#             */
/*   Updated: 2023/11/16 23:42:21 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief The strlcat() function concatenates strings
/// @param dst pointer to the destination string to be extended
/// @param src pointer to the source string to be copied over
/// @param dstsize size of the destination string INCLUDING '\0'
/// @return length of dst plus the length of src
size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	dst_len;

	i = 0;
	j = -1;
	dst_len = ft_strlen(dst);
	if (dstsize < dst_len || dstsize == 0)
		return (ft_strlen(src) + dstsize);
	while (dst[i] != '\0' && i < dstsize)
		i++;
	while (i + ++j < dstsize - 1 && src[j])
		dst[i + j] = src[j];
	dst[i + j] = '\0';
	return (dst_len + ft_strlen(src));
}
