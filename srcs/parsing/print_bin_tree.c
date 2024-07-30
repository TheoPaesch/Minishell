/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bin_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:12:00 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/30 15:06:18 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Retrieves a string representation of a node type.
 * @param type The integer value representing the node type.
 * @return const char* The string representation of the node type.
 */
const char	*get_node_type_str(int type)
{
	static const char	*types[] = {"EXEC", "REDIR", "PIPE", "LIST", "BACK",
		"UNKNOWN"};
	int					i;

	type--;
	i = sizeof(types) / sizeof(types[0]);
	if (type >= 0 && type < i - 1)
		return (types[type]);
	else
		return (types[i - 1]);
}

/**
 * @brief Prints spaces for tree indentation.
 * This function prints a specified number of spaces to the standard output,
 * used for indenting nodes in the tree when printing.
 * @param space The total number of spaces to print.
 */
void	print_spaces(int space)
{
	int	i;

	i = 10;
	while (i++ < space)
		printf(" ");
}

/**
 * @brief Identifies a node and prints its type.
 * This function indents the line according to the `space` parameter, then
 * prints the type of the node in a formatted manner. The node type is obtained
 * by calling `get_node_type_str`.
 *
 * @param node The command node to process.
 * @param space The indentation level for printing.
 */
void	process_and_print_node(t_cmd *node, int space)
{
	print_spaces(space);
	printf("─ %s\n", get_node_type_str(node->type));
}

/**
 * @brief Utility function to recursively print the binary tree.
 *
 * This function recursively traverses the binary tree,
 * printing each node's type with appropriate indentation.
 * It handles special node types such as PIPE and LIST differently to
 * maintain the correct structure in the printed output.
 *
 * @param node The current node being processed.
 * @param space The current indentation level.
 * @return t_cmd* The same node passed as input.
 */
t_cmd	*print_tree_util(t_cmd *node, int space)
{
	if (node == NULL || DEBUG_FLAG == false)
		return (node);
	space += 10;
	if (node->type == PIPE || node->type == LIST)
		print_tree_util(((t_pipe_cmd *)node)->right, space);
	printf("\n");
	process_and_print_node(node, space);
	if (node->type == REDIR)
		print_tree_util(((t_redir_cmd *)node)->cmd, space);
	if (node->type == PIPE || node->type == LIST)
		print_tree_util(((t_pipe_cmd *)node)->left, space);
	return (node);
}

/// @brief Entry point to print MuShell's binary tree
/// @param root The root node of the binary tree
/// @return Nothing
t_cmd	*print_tree(t_cmd *root)
{
	return (print_tree_util(root, 0));
}
