/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:50:02 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/11 17:58:21 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	first = *stack;
	last = last_node(*stack);
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

void	rotate_stack(t_stack_node **stack, char c)
{
	rotate(stack);
	if (c == "a")
		ft_printf("ra\n");
	if (c == "b")
		ft_printf("rb\n");
}