/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:26:04 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/09 18:02:10 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies n bytes from memory area src to memory area dst.
/// @param dst 	Destination to copy to.
/// @param src 	Source to copy from.
/// @param n	Amount of bytes.
/// @return		Pointer to dst.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	i;
	unsigned char	*dstx;
	unsigned char	*srcx;

	dstx = (unsigned char *)dst;
	srcx = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	while (i++ < n)
		dstx[i] = srcx[i];
	return (dst);
}
