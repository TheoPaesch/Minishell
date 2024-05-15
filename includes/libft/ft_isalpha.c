/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:30:55 by mstrauss          #+#    #+#             */
/*   Updated: 2023/11/16 22:25:38 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief		checks if character is alphabetical in ASCII
/// @param num	character
/// @return		the character if it is true
int	ft_isalpha(int num)
{
	if ((num >= 65 && num <= 90) || (num >= 97 && num <= 122))
		return (num);
	return (0);
}
