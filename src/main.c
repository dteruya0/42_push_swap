/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:32:39 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/11 16:50:08 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv, argc == 2);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			swap_stack(&a, 'a');
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			push_swap();
	}
	free_stack(&a);
	if (argc == 2)
		free_matrix(argv);
	return (0);
}
