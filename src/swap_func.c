/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:30:44 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/11 17:26:43 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **stack)
{
	int				size;
	t_stack_node	*first;
	t_stack_node	*second;

	size = stack_len(*stack);
	if (size == 1 || stack == NULL || *stack == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	*stack = (*stack)-> next;
	(*stack)->next = first;
	(*stack)->next->next = second;
}

void	swap_stack(t_stack_node **stack, char c)
{
	swap(stack);
	if (c == "a")
		ft_printf("sa\n");
	if (c == "b")
		ft_printf("sb\n");
}
