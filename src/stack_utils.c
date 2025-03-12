/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:27:26 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/12 19:20:09 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_len(t_stack *stack)
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

t_stack	*prev_last_node(t_stack *stack)
{
	t_stack	*prev_last;

	if (stack == NULL)
		return (NULL);
	prev_last = stack;
	while (stack->next)
	{
		prev_last = stack;
		stack = stack->next;
	}
	return (prev_last);
}

void	append_node(t_stack **stack, int nbr)
{
	t_stack *node;

	node = new_node(nbr);
	if (*stack == NULL)
		*stack = node;
	else
		add_back(stack, node);
}

t_stack	*find_biggest(t_stack *stack)
{
	t_stack	*biggest;

	if (stack == NULL)
		return (NULL);
	biggest = stack;
	while (stack)
	{
		if (biggest->value < stack->value)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}
