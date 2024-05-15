/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:32:28 by mstrauss          #+#    #+#             */
/*   Updated: 2023/12/14 20:17:35 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RULES
// • Don’t implement the buffer management of the original printf().
// • Your function has to handle the following conversions: cspdiuxX%
// • Your function will be compared against the original printf().

// CONTENT TO BE PROCESSED
// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.

#include "libft.h"

int	pf_putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	pf_putstr(char *s, int fd)
{
	int	rtrncnt;
	int	tmp;

	if (s == NULL)
		return (write(1, "(null)", 6));
	rtrncnt = 0;
	while (*s)
	{
		tmp = write(fd, s, 1);
		if (tmp == -1)
			return (-1);
		rtrncnt += tmp;
		s++;
	}
	return (rtrncnt);
}

static int	pf_router(char type, va_list args)
{
	if (type == 'c')
		return (pf_putchar(va_arg(args, int), 1));
	if (type == 's')
		return (pf_putstr(va_arg(args, char *), 1));
	if (type == 'p')
		return (pf_putptr((unsigned long int)(va_arg(args, void *))));
	if (type == 'd' || type == 'i')
		return (pf_itoa(va_arg(args, int)));
	if (type == 'u')
		return (pf_utoa(va_arg(args, unsigned long)));
	if (type == 'x')
		return (pf_tohexlower(va_arg(args, unsigned int)));
	if (type == 'X')
		return (pf_tohexupper(va_arg(args, unsigned int)));
	if (type == '%')
		return (pf_putchar('%', 1));
	return (-1);
}

/// @brief The ft_printf utility formats and prints its arguments, after
/// the first, under control of the format.The format is a character string
/// which contains three types of objects : plain characters,
///	which are simply copied to standard output,
///	character escape sequences which are converted and copied to the standard
/// output, and format specifications,
///	each of which causes printing of the next successive argument.
/// @param str String to be printed and placeholders filled
/// @param ... Additional parameters to build the string
/// @return
int	pf_printf(const char *str, ...)
{
	va_list	args;
	int		printedchars;
	int		tmp;

	va_start(args, str);
	printedchars = 0;
	str = (char *)str;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			tmp = pf_router(*str, args);
		}
		else
			tmp = pf_putchar(*str, 1);
		str++;
		if (tmp < 0)
			return (-1);
		printedchars += tmp;
	}
	va_end(args);
	return (printedchars);
}
