/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:27:26 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/11 17:36:58 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	size;

	if (stack == NULL)
		return (0);
	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack_node	*last_node(t_stack_node *stack)
{
	t_stack_node	*last;

	while(stack)
	{
		if (stack->next == NULL)
			last = stack;
		stack = stack->next;
	}
	return (last);
}

void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node *node;

	node = new_node(nbr);
	if (*stack == NULL)
		*stack = node;
	else
		add_back(stack, node);
}
