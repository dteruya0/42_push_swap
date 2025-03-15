/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:17:49 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/15 20:30:19 by dteruya          ###   ########.fr       */
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

static void	final_sort(t_stack **a)
{
	t_stack	*small;
	int		times;

	mov_cost(*a, 'a');
	small = find_smallest(*a);
	times = small->cost_a;
	while (times > 0)
	{
		if (small->move_a == 'u')
			rotate_stack(a, 'a');
		else
			rev_rotate_stack(a, 'a');
		times--;
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*node_a;
	t_stack *node_b;

	node_a = NULL;
	node_b = NULL;
	push_stack(a, b, 'b');
	push_stack(a, b, 'b');
	while (stack_len(*a) > 3)
	{
		node_a = calc_cost(*a, *b, 'a', 'b');
		node_b = fit_in_b(node_a, *b);
		rot(a, b, node_a, node_b);
		push_stack(a, b, 'b');
	}
	tiny_sort(a);
	while (stack_len(*b) > 0)
	{
		node_b = calc_cost(*b, *a, 'b', 'a');
		node_a = fit_in_a(node_b, *a);
		rot(a, b, node_a, node_b);
		push_stack(b, a, 'a');
	}
	final_sort(a);
}


//i sent 2 numbers tu stack b, know i need to verify the cost and where my stack will roll, a or down.