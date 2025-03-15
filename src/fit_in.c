/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:55:52 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/15 20:31:42 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*other_place(t_stack *stack, char c)
{
	int	nbr;
	t_stack	*place;

	if (c == 'a')
		nbr = 2147483647;
	else
		nbr = -2147483648;
	while (stack)
	{
		if (c == 'a' && stack->value < nbr)
		{
			nbr = stack->value;
			place = stack;
		}
		else if (c == 'b' && stack->value >= nbr)
		{
			nbr = stack->value;
			place = stack;
		}
		stack = stack->next;
	}
	return (place);
}

t_stack	*fit_in_b(t_stack *a, t_stack *b)
{
	int		nbr;
	t_stack	*stack;
	t_stack	*place;

	place = NULL;
	stack = b;
	nbr = -2147483648;
	while (stack)
	{
		if (a->value > stack->value && nbr < stack->value)  // Este if verifica se, o valor da stack A é maior que algum dos valores na stack B &&
		{                                                   // Se o nbr é manor que o valor da stack B e assim precisamos encontrar o maior valor que seja menor do que o valor da stack A.
			nbr = stack->value;
			place = stack;
		}
		stack = stack->next;
	}
	if (!place)
		place = other_place(b, 'b');
	return (place);
}

t_stack	*fit_in_a(t_stack *node_b, t_stack *a)
{
	int		nbr;
	t_stack	*stack;
	t_stack	*place;

	place = NULL;
	stack = a;
	nbr = 2147483647;
	while (stack)
	{
		if (node_b->value < stack->value && nbr > stack->value)
		{
			nbr = stack->value;
			place = stack;
		}
		stack = stack->next;
	}
	if (!place)
		place = other_place(a, 'a');
	return (place);
}


/*
7
5
6
4
2      9
3     15
*/