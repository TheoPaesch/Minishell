#include "env.h"
#include "minishell.h"

void	ft_get_input(char **env)
{
	int		i;
	s_env	*env;
	s_env	*expo;

	i = 0;
	while (*env[i] != NULL)
		i++;
	ft_malloc(env, sizeof(s_env) * i);
	ft_malloc(expo, sizeof(s_env) * i);
	/* build linked list for env ad fill with befor "=" and after*/
}
