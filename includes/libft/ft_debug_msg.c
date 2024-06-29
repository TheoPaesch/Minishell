#include "../libft.h"

void	ft_debug_msg(char *msg)
{
	// if (get_shell()->debug_flag == true)
	// {
	ft_putstr_fd("DEBUG: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	// }
}
