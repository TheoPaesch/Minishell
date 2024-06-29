#include "minishell.h"

static const char	*g_whitespace = " \t\r\n\v";

int	scan_skip_ws(char **ptr_str, char *end_str, char *tokens)
{
	char	*str;

	str = *ptr_str;
	while (str < end_str && ft_strchr(g_whitespace, *str))
		str++;
	*ptr_str = str;
	if (*str && ft_strchr(tokens, *str))
		return (true);
	else
		return (false);
}

// check behaviour later