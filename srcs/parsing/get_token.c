#include <minishell.h>

/*
IDEAS:
- while iterating over word, use ft_isalnum instead?
*/

/// @brief Parses the Input, optional pointers for the start and end of a
/// token can be returned by passing appropriate pointers. Pass NULL if
/// you don't want that.
/// @param ptr_str 	String to be parsed
/// @param end_str	End of String to be parsed
/// @param quote	Beginning of token
/// @param end_quote End of token
/// @return	indicator on what type of token we are currently pointing to
///	x = text
///	+ = >>
int	get_token(char **ptr_str, char *end_str, char **quote, char **end_quote)
{
	char	*tmp;
	int		return_val;

	tmp = *ptr_str;
	while (tmp < end_str && ft_strchr(" \t\r\n\v ", *tmp))
		tmp++;
	if (quote)
		*quote = tmp;
	return_val = *tmp;
	if (*tmp == '\0')
		;
	else if (ft_strchr("|();&<", *tmp)) // DBG: CHECK WHY TRUE WHEN ptr@endstr
		tmp++;
	else if (*tmp == '>')
	{
		tmp++;
		if (*tmp == '>')
		{
			return_val = '+';
			tmp++;
		}
	}
	else
	{
		return_val = 'x';
		while (tmp < end_str && !ft_strchr(" \t\r\n\v<|>&;()", *tmp))
			tmp++;
	}
	if (end_quote)
		*end_quote = tmp;
	while (tmp < end_str && ft_strchr(" \t\r\n\v", *tmp))
		tmp++;
	*ptr_str = tmp;
	return (return_val);
}
