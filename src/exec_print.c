/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:52:00 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/12 20:00:01 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_stack(t_stack **stack, char c)
{
	swap(stack);
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
}

void	rotate_stack(t_stack **stack, char c)
{
	rotate(stack);
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
}

void	rev_rotate_stack(t_stack **stack, char c)
{
	rev_rotate(stack);
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}

void	push_stack(t_stack **src, t_stack **dest, char end)
{
	push(src, dest);
	if (end == 'a')
		ft_printf("pa\n");
	if (end == 'b')
		ft_printf("pb\n");
}
