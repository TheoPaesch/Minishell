/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bin_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:12:00 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/07 13:47:04 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char	*get_node_type_str(int type) // DBG ONLY, REMOVE FILE!!!
{
	static const char *types[] = {"EXEC", "REDIR", "PIPE", "LIST", "BACK",
		"UNKNOWN"};
	int typeCount;

	typeCount = sizeof(types) / sizeof(types[0]);
	return ((type >= 0 && type < typeCount - 1) ? types[type] : types[typeCount
		- 1]);
}

void	print_spaces(int space)
{
	int	i;

	i = 10;
	while (i++ < space)
		printf(" ");
}

void	process_and_print_node(t_cmd *node, int space)
{
	print_spaces(space);
	printf("─ %s\n", get_node_type_str(node->type));
}

t_cmd	*print_tree_util(t_cmd *node, int space)
{
	if (node == NULL || DEBUG_FLAG == false)
		return (node);
	space += 10;
	if (node->type == PIPE || node->type == LIST)
		print_tree_util(((t_pipe_cmd *)node)->right, space);
	printf("\n");
	process_and_print_node(node, space);
	if (node->type == PIPE || node->type == LIST)
		print_tree_util(((t_pipe_cmd *)node)->left, space);
	return (node);
}

t_cmd	*print_tree(t_cmd *root)
{
	return (print_tree_util(root, 0));
}
