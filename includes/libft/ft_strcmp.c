/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:38:32 by tpaesch           #+#    #+#             */
/*   Updated: 2024/06/04 18:46:40 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int ft_strcmp(const char *s1, const char *s2)
{
    unsigned char	*str1;
    unsigned char	*str2;
    size_t			i;

    str1 = (unsigned char *)s1;
    str2 = (unsigned char *)s2;
    i = 0;
    while (str1[i] && str2[i] && str1[i] == str2[i])
        i++;
    return (str1[i] - str2[i]);
}
