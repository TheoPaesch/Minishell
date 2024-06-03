/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:08:10 by tpaesch           #+#    #+#             */
/*   Updated: 2024/05/27 14:15:05 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char	    *str;

	str = s;
	i = 0;
	while (n > i)
	{
		str[i] = '\0';
		i++;
	}
}