/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:17:49 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/12 15:59:09 by dteruya          ###   ########.fr       */
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
