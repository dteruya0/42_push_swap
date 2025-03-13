/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:17:49 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/13 14:01:34 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	tiny_sort(t_stack **stack)
{
	t_stack	*biggest;

	biggest = find_biggest(*stack);
	if (biggest == *stack)
		rotate_stack(stack, 'a');
	else if (biggest == (*stack)->next)
		rev_rotate_stack(stack, 'a');
	if ((*stack)->value > (*stack)->next->value)
		swap_stack(stack, 'a');
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*node_a;
	t_stack *node_b;
	
	push_stack(a, b, 'b');
	push_stack(a, b, 'b');
	while (stack_len(*a) > 3)
	{
		node_a = calc_cost(*a, *b, 'a', 'b');
	}
	while (stack_len(*b) > 0)
	{
		
	}
}


//i sent 2 numbers tu stack b, know i need to verify the cost and where my stack will roll, a or down.