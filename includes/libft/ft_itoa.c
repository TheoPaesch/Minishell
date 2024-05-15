/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:21:19 by mstrauss          #+#    #+#             */
/*   Updated: 2023/11/16 22:29:32 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigit(int n)
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

static unsigned long	ft_posnum(int n)
{
	if (n < 0)
		return ((unsigned long)n * -1);
	else
		return ((unsigned long)n);
}

static char	*ft_itoa_conv(char *s, unsigned long n_unsg,
		unsigned long char_count, unsigned long neg)
{
	if (neg == 1)
		*s = '-';
	while (char_count > 0)
	{
		s[char_count - 1 + neg] = (n_unsg % 10) + '0';
		n_unsg = n_unsg / 10;
		char_count--;
	}
	return (s);
}

/// @brief 		Allocates (with malloc(3)) and returns a string
///				representing the integer received as an argument.
///				Negative numbers must be handled.
/// @param n	String representing the integer.
/// @return		NULL if the allocation fails.
char	*ft_itoa(int n)
{
	unsigned long	char_count;
	unsigned long	neg;
	char			*ptr;
	unsigned long	n_unsg;

	neg = 0;
	if (n == 0)
	{
		ptr = ft_calloc(1, 2);
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '0';
		return (ptr);
	}
	if (n < 0)
		neg++;
	n_unsg = ft_posnum(n);
	char_count = ft_countdigit(n);
	ptr = ft_calloc(1, char_count + 1 + neg);
	if (ptr == NULL)
		return (NULL);
	ft_itoa_conv(ptr, n_unsg, char_count, neg);
	return (ptr);
}
