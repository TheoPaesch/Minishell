/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:20:35 by mstrauss          #+#    #+#             */
/*   Updated: 2023/11/16 23:36:58 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Applies the function ’f’ on each character of
///				the string passed as argument, passing its index
///				as first argument. Each character is passed by
///				address to ’f’ to be modified if necessary.
/// @param s 	String on which to iterate.
/// @param f 	Function to apply to each character.
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = -1;
	while (s[++i])
		f(i, &s[i]);
}
