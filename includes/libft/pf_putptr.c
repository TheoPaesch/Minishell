/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:01:06 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/17 16:09:38 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	pf_putptr(unsigned long int n)
{
	int	tmp;

	tmp = 0;
	tmp = write(1, "0x", 2);
	if (tmp == -1)
		return (tmp);
	return (pf_tohexlower(n) + tmp);
}
