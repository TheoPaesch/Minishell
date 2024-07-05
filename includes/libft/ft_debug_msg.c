#include "../libft.h"

void	ft_debug_msg(char *msg)
{
	if (DEBUG_FLAG == true)
	{
		ft_putstr_fd("DEBUG: ", 2);
		ft_putstr_fd(msg, 2);
		ft_putchar_fd('\n', 2);
	}
}
