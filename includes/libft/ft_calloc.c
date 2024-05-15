/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:19:46 by mstrauss          #+#    #+#             */
/*   Updated: 2023/11/16 22:17:27 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Contiguously allocates enough space for count objects
///			that are size bytes of memory filled with bytes of value zero
/// @param count amount of objects
/// @param size bytesize of an object
/// @return If successful calloc returns a pointer to allocated memory.
/// If there is an error, they return a NULL pointer and set errno to ENOMEM.
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	unsigned long	i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	return (ft_bzero(ptr, count * size), ptr);
}
