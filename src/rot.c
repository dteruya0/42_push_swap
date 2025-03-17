/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:21:53 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/17 14:04:41 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	same_rot(int *only_a, int *only_b, t_stack *node_a, t_stack *node_b)
{
	int	both;

	both = 0;
	if (node_a->cost_a <= node_b->cost_b)
	{
		both = node_a->cost_a;
		*only_a = 0;
		*only_b = node_b->cost_b - node_a->cost_a;
	}
	else
	{
		both = node_b->cost_b;
		*only_b = 0;
		*only_a = node_a->cost_a - node_b->cost_b;
	}
	return (both);
}

void	rot_both(int both, t_stack **a, t_stack **b, char c)
{
	while (both > 0)
	{
		rotate_both_stack(a, b, c);
		both--;
	}
}

static void	rot_a(t_stack **a, int only_a, char c)
{
	while (only_a > 0)
	{
		if (c == 'u')
			rotate_stack(a, 'a');
		else
			rev_rotate_stack(a, 'a');
		only_a--;
	}
}

static void	rot_b(t_stack **b, int only_b, char c)
{
	while (only_b > 0)
	{
		if (c == 'u')
			rotate_stack(b, 'b');
		else
			rev_rotate_stack(b, 'b');
		only_b--;
	}
}

void	rot(t_stack **a, t_stack **b, t_stack *node_a, t_stack *node_b)
{
	int	both;
	int	only_a;
	int	only_b;

	both = 0;
	only_a = node_a->cost_a;
	only_b = node_b->cost_b;
	if (node_a->move_a == node_b->move_b)
	{
		both = same_rot(&only_a, &only_b, node_a, node_b);
		rot_both(both, a, b, node_a->move_a);
	}
	rot_a(a, only_a, node_a->move_a);
	rot_b(b, only_b, node_b->move_b);
}
