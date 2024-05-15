/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:44:49 by mstrauss          #+#    #+#             */
/*   Updated: 2024/03/09 18:16:28 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 	copies len bytes from string src to string dst.
///			The two strings may overlap;
///			the copy is always done in a non-destructive manner.
/// @param dst	Destination to copy to.
/// @param src	Source to copy from.
/// @param len	Amount of bytes to copy.
/// @return		Original value of dst.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;
	unsigned char	*dstx;
	unsigned char	*srcx;

	dstx = (unsigned char *)dst;
	srcx = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	if (src > dst)
	{
		while (i < len)
		{
			dstx[i] = srcx[i];
			i++;
		}
	}
	while (i < len)
	{
		dstx[len - 1 - i] = srcx[len - 1 - i];
		i++;
	}
	return (dst);
}
