/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:42:35 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/14 18:06:36 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief 		Applies the function ’f’ to each character of the
///				string ’s’, and passing its index as first argument
///				to create a new string (with ft_malloc(3)) resulting
///				from successive applications of ’f’.
/// @param s 	String on which to iterate.
/// @param f 	function to apply to each character.
/// @return 	The string created from the successive applications of ’f’.
///				NULL if the allocation fails.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s2;

	i = -1;
	s2 = NULL;
	s2 = ft_malloc(ft_strlen(s) + 1);
	if (!s2)
		exit(1);
	while (s[++i])
		s2[i] = f(i, s[i]);
	s2[i] = '\0';
	return (s2);
}
