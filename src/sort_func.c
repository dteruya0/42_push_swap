/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:30:44 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/15 18:04:10 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	*stack = second;
	first->next = second->next;
	second->next = first;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = last_node(*stack);
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*prev_last;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	last = last_node(*stack);
	prev_last = prev_last_node(*stack);
	last->next = *stack;
	*stack = last;
	prev_last->next = NULL;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*node;

	if (src == NULL || *src == NULL)
		return ;
	node = *src;
	*src = (*src)->next;
	node->next = *dest;
	*dest = node;
}
