/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:33:11 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/17 13:13:20 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = sign * -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result * sign);
}

void	stack_init(t_stack **a, char **argv, bool flag_argc_2)
{
	long	n;
	int		i;

	i = 0;
	if (!flag_argc_2)
		i = 1;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_error(a, argv, flag_argc_2);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(a, argv, flag_argc_2);
		if (error_duplicate(*a, (int)n))
			free_error(a, argv, flag_argc_2);
		append_node(a, (int)n);
		i++;
	}
}
