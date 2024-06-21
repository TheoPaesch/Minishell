#include "minishell.h"

void	exit_child(int ext_stat)
{
	if (getppid() != getpid())
		exit(ext_stat);
}
