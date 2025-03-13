/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:01:36 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/13 17:26:28 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*new_node(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->value = content;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->move_a = '\0';
	new_node->move_b = '\0';
	new_node->next = NULL;
	return (new_node);
}

t_stack	*last_node(t_stack *stack)
{
	t_stack	*node;

	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->next == NULL)
			node = stack;
		stack = stack->next;
	}
	return (node);
}

void	add_back(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (stack == NULL || node == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	last = last_node(*stack);
	last->next = node;
}
