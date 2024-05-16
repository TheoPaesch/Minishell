/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:24:33 by mstrauss          #+#    #+#             */
/*   Updated: 2024/05/15 17:19:14 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
The input is processed one symbol at a time:
- If a variable or number is found, it is copied directly to the output.
- If the symbol is an OPERATOR, it is pushed onto the operator stack.
- If the operator's precedence is lower than that of the operators at the top
of the stack or the precedences are equal and the operator is left associative,
then that operator is popped off the stack and added to the output.
Finally,any remaining operators are popped off the stack and added to the output
*/

void	shunting_yard(void)
{
	t_list	*output;
	t_list	*operators;
	t_list	*input;
	t_list	*tmp;

	output = NULL;
	operators = NULL;
	input = NULL;
	tmp = NULL;
	while (input)
	{
		if (input->type == OPERATOR)
		{
			if (operators == NULL)
				ft_lstadd_back(&operators, ft_lstnew(input->content));
			else if (precedence(input->content) > precedence(operators->content))
				ft_lstadd_back(&operators, ft_lstnew(input->content));
			else
			{
				while (operators
					&& precedence(input->content) <= precedence(operators->content))
				{
					ft_lstadd_back(&output, ft_lstnew(operators->content));
					tmp = operators;
					operators = operators->next;
					ft_free(tmp);
				}
				ft_lstadd_back(&operators, ft_lstnew(input->content));
			}
		}
		else
			ft_lstadd_back(&output, ft_lstnew(input->content));
		input = input->next;
	}
	while (operators)
	{
		ft_lstadd_back(&output, ft_lstnew(operators->content));
		tmp = operators;
		operators = operators->next;
		ft_free(tmp);
	}
}

// while there are tokens to be read:
//     read a token
//     if the token is:
//     - a number:
//         put it into the output queue
//     - a function:
//         push it onto the operator stack
//     - an operator o1:
//         while (
//             there is an operator o2 at the top of the operator stack which is not a left parenthesis,
//             and (o2 has greater precedence than o1 or (o1 and o2 have the same precedence and o1 is left-associative))
//         ):
//             pop o2 from the operator stack into the output queue
//         push o1 onto the operator stack
//     - a ",":
//         while the operator at the top of the operator stack is not a left parenthesis:
//              pop the operator from the operator stack into the output queue
//     - a left parenthesis (i.e. "("):
//         push it onto the operator stack
//     - a right parenthesis (i.e. ")"):
//         while the operator at the top of the operator stack is not a left parenthesis:
//             {assert the operator stack is not empty}
//             /* If the stack runs out without finding a left parenthesis,
//              then there are mismatched parentheses. */
//             pop the operator from the operator stack into the output queue
//         {assert there is a left parenthesis at the top of the operator stack}
//         pop the left parenthesis from the operator stack and discard it
//         if there is a function token at the top of the operator stack, then:
//             pop the function from the operator stack into the output queue
// /* After the while loop,
//	pop the remaining items from the operator stack into the output queue. */
// while there are tokens on the operator stack:
//     /* If the operator token on the top of the stack is a parenthesis,
//          then there are mismatched parentheses.* /
//     {assert the operator on top of the stack is not a (left) parenthesis}
//     pop the operator from the operator stack onto the output queue

void	shunting_yard(t_list *input)
{
	t_list	*output;
	t_list	*operators;

	output = NULL;
	operators = NULL;
	while (input)
	{
		if (input->type == NUMBER)
		{
		}
		else if (input->type == FUNCTION)
		{
		}
		else if (input->type == OPERATOR_1)
		{
			while (operator->type == OPERATOR_2 && operators->symbol != '(')
			{
				/* code */
			}
			// while (operators != NULL && operators->symbol != '(')
			// {
			// 	push(operators, output);
			// 	ft_lstdelone(operator)
			// }
		}
		input = input->next;
	}
}
