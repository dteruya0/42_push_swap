/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:27:26 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/10 16:56:02 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	
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
