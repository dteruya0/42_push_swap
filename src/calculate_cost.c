/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:02:38 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/17 17:26:01 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	type_move(t_stack *stack, int size, char c)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (i <= size / 2)
		{
			if (c == 'a')
				stack->move_a = 'u';
			else
				stack->move_b = 'u';
		}
		else
		{
			if (c == 'a')
				stack->move_a = 'd';
			else
				stack->move_b = 'd';
		}
		i++;
		stack = stack->next;
	}
}

void	mov_cost(t_stack *stack, char c)
{
	int	i;
	int	size;
	int	cost;

	size = stack_len(stack);
	i = 1;
	cost = 0;
	type_move(stack, size, c);
	while (stack)
	{
		if (c == 'a')
			stack->cost_a = cost;
		else
			stack->cost_b = cost;
		if (i <= size / 2)
			cost++;
		else if (((i > (size / 2 + 1)) || (size % 2 == 0)))
			cost--;
		stack = stack->next;
		i++;
	}
}

static int	move_total(t_stack *a, t_stack *b)
{
	int	total;

	total = 0;
	if (a->move_a == b->move_b)
	{
		if (a->cost_a >= b->cost_b)
			total = a->cost_a;
		else
			total = b->cost_b;
	}
	else
		total = a->cost_a + b->cost_b;
	return (total);
}

static int	total_cost(t_stack *s_src, t_stack *s_dest, char src)
{
	int		total;
	t_stack	*fit_in;

	total = 1;
	if (src == 'a')
	{
		fit_in = fit_in_b(s_src, s_dest);
		total = total + move_total(s_src, fit_in);
	}
	else
	{
		fit_in = fit_in_a(s_src, s_dest);
		total = total + move_total(fit_in, s_src);
	}
	return (total);
}

t_stack	*calc_cost(t_stack *s_src, t_stack *s_dest, char src, char dest)
{
	t_stack	*lowest_cost;
	int		lowest;
	int		total;

	lowest = 100000;
	mov_cost(s_src, src);
	mov_cost(s_dest, dest);
	while (s_src)
	{
		total = total_cost(s_src, s_dest, src);
		if (lowest > total)
		{
			lowest = total;
			lowest_cost = s_src;
		}
		s_src = s_src->next;
	}
	return (lowest_cost);
}
