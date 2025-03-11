/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:17:49 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/11 15:44:21 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack_node **stack)
{
	t_stack_node	*biggest;

	biggest = find_biggest(*stack);
	if (biggest == *stack)
		rotate_stack();
	else if (biggest == (*stack)->next)
		rotate_rev_stack();
	if ((*stack)->value > (*stack)->next->value)
		swap(stack);
}

// onde está o maior valor na stack

t_stack_node *find_biggest(t_stack_node *a)
{
	t_stack_node	*biggest;

	biggest = a;
	while (a)
	{
		if (biggest->value < a->next->value)
			biggest = a->next;
		a = a->next;
	}
	return (biggest);
}
