/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:21:19 by mstrauss          #+#    #+#             */
/*   Updated: 2023/12/14 20:17:21 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pf_countdigit(int n)
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

static unsigned long	pf_posnum(int n)
{
	if (n < 0)
		return ((unsigned long)n * -1);
	else
		return ((unsigned long)n);
}

static char	*pf_itoa_conv(char *s, unsigned long n_unsg,
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
int	pf_itoa(int n)
{
	unsigned long	char_count;
	unsigned long	neg;
	char			*ptr;
	unsigned long	n_unsg;
	int				tmp;

	neg = 0;
	if (n == 0)
		return (pf_putstr("0", 1));
	if (n < 0)
		neg++;
	n_unsg = pf_posnum(n);
	char_count = pf_countdigit(n);
	ptr = ft_calloc(1, char_count + 1 + neg);
	if (ptr == NULL)
		return (-1);
	ptr = pf_itoa_conv(ptr, n_unsg, char_count, neg);
	tmp = pf_putstr(ptr, 1);
	free(ptr);
	return (tmp);
}
