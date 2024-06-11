/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:36:12 by mstrauss          #+#    #+#             */
/*   Updated: 2024/06/12 00:35:39 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Joins a variable amount of strings to a single one.
/// Frees the src strings if 'bool free' is 1.
/// @param count amount of strings to be joined
/// @param free deletes src strings after joining
/// @param
/// @return One big STR
char	*ft_strjoinall(int count, bool free, ...)
{
	int		total_len;
	int		i;
	char	*str;
	char	*tmp;
	va_list	args;

	va_start(args, free);
	total_len = 0;
	i = 0;
	while (i < count)
		total_len += ft_strlen(va_arg(args, char *));
	va_end(args);
	str = ft_calloc(sizeof(char), total_len + 1);
	if (!str)
		return (NULL);
	i = 0;
	va_start(args, free);
	while (i < count)
	{
		tmp = va_arg(args, char *);
		ft_strcat(str, tmp);
		if (free)
			ft_free(tmp);
	}
	return (va_end(args), str);
}
