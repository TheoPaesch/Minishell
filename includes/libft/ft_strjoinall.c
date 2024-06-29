/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:36:12 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/29 19:48:19 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Joins a variable amount of strings to a single one.
/// Frees the src strings if 'int del' is 1.
/// @param count amount of strings to be joined
/// @param del deletes src strings after joining
/// @param ... The strings to be joined
/// @return One big STR
char	*ft_strjoinall(int count, int del, ...)
{
	int		total_len;
	int		i;
	char	*str;
	char	*tmp;
	va_list	args;

	va_start(args, del);
	total_len = 0;
	i = 0;
	while (i++ < count)
		total_len += ft_strlen(va_arg(args, char *));
	va_end(args);
	str = ft_calloc(sizeof(char), total_len + 1);
	if (!str)
		return (NULL);
	i = 0;
	va_start(args, del);
	while (i++ < count)
	{
		tmp = va_arg(args, char *);
		ft_strlcat(str, tmp, total_len + 1);
		if (del)
			tmp = ft_free(tmp);
	}
	return (va_end(args), str);
}

// DOES NOT check if incoming strs are NULL