/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_skip_ws.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:09:06 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/30 18:11:41 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**

	* @brief Skips whitespace characters in a string and checks for specific tokens.

	* This function advances the pointer `*ptr_str` through any leading whitespace characters
 * (space, tab, carriage return, newline,
	vertical tab) until a non-whitespace character

	* is encountered or the end of the string (`end_str`) is reached. If the next character
 * is one of the specified `tokens`, the function returns `true`; otherwise,
	it returns
 * `false`.
 *
 * @param ptr_str A pointer to the string pointer to be advanced. On return,

	* `*ptr_str` points to the first non-whitespace character or the end of the string.

	* @param end_str A pointer to the end of the string. This function will not read beyond
 *                this point.

	*  @param tokens A string containing token characters to check for after skipping whitespace.
 *               If the first non-whitespace character is found in `tokens`,
 * the function
 *  returns `true`.
 *

	*  @return int Returns `true` (1) if the first non-whitespace character is a token character,
 *             `false` (0) otherwise.
 */
int	scan_skip_ws(char **ptr_str, char *end_str, char *tokens)
{
	char	*str;

	str = *ptr_str;
	while (str < end_str && ft_strchr(" \t\r\n\v", *str))
		str++;
	*ptr_str = str;
	if (*str && ft_strchr(tokens, *str))
		return (true);
	else
		return (false);
}

// check behaviour later