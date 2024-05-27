/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:19:46 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/27 13:51:34 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Contiguously allocates enough space for count objects
///			that are size bytes of memory filled with bytes of value zero
/// @param count amount of objects
/// @param size bytesize of an object
/// @return If successful calloc returns a pointer to allocated memory.
/// If there is an error, they return a NULL pointer and set errno to ENOMEM.
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	ptr = NULL;
	if (ft_malloc(ptr, (count * size)))
		{
			printf("Error: malloc failed in calloc\n");
			exit(1);
		}
	if (ptr == NULL)
		return (NULL);
	return (ft_bzero(ptr, count * size), ptr);
}
