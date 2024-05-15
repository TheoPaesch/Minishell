/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:21:19 by mstrauss          #+#    #+#             */
/*   Updated: 2023/12/14 20:02:39 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pf_countdigit(unsigned int n)
{
	int	char_count;

	char_count = 0;
	while (n != 0)
	{
		n = n / 10;
		char_count++;
	}
	return (char_count);
}

static char	*pf_utoa_conv(char *s, unsigned int n, unsigned int char_count)
{
	while (char_count > 0)
	{
		s[char_count - 1] = (n % 10) + '0';
		n = n / 10;
		char_count--;
	}
	return (s);
}

/// @brief 		Allocates (with malloc(3)) and returns a string
///				representing the integer received as an argument.
///				Negative numbers must be handled.
/// @param n	String representing the integer.
/// @return		NULL if the allocation fails.
int	pf_utoa(unsigned int n)
{
	unsigned int	char_count;
	char			*ptr;
	int				tmp;

	if (n == 0)
		return (pf_putstr("0", 1));
	char_count = pf_countdigit(n);
	ptr = ft_calloc(sizeof(char), char_count + 1);
	if (ptr == NULL)
		return (-1);
	ptr = pf_utoa_conv(ptr, n, char_count);
	tmp = pf_putstr(ptr, 1);
	free(ptr);
	return (tmp);
}
