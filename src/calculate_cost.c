/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:02:38 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/13 17:53:47 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Essa função ajuda a entender se o movimento para que o valor chegue no topo deve ser
por cima(up) ou por baixo(down) e assim usando ra/rb ou rra/rrb, respectivamente.
*/

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
/*
Esta função pega o custo da movimentação para por no topocada nó.
Como começa no indice 1 e cost 0, pois o primeiro nó já está encima.
*/
void	mov_cost(t_stack *stack, char c)
{
	int i;
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
		else if (!((i <= (size / 2) + 1) && (size % 2 != 0)))
			cost--;
		stack = stack->next;
		i++;
	}
}

t_stack	*calc_cost(t_stack *s_src, t_stack *s_dest, char src, char dest)
{
	t_stack	*lowest_cost;

	mov_cost(s_src, src);
	mov_cost(s_dest, dest);
	
	
	return (lowest_cost);
}

// para enviar o nó de menor custo:

/*
	1º) preciso retornar o nó de menor custo
	2º) descobrir qual o menor custo em a + o menor custo para encaixa-lo no b
	2a) para descobrir o menor custo em a:
	Verificar qual o indice do número para que ele chegue no topo:
	

	v -> value
	c -> cost
	i -> index
	t -> type mov
	v-c-i-t
	4|0|0|u
	9|1|1|u
	7|2|2|u
	2|2|3|d
	5|1|4|d
	
	
*/
