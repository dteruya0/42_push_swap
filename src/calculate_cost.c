/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:02:38 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/17 13:02:58 by dteruya          ###   ########.fr       */
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
Esta função pega o custo da movimentação para por no topo cada nó.
Começa no indice 1 e cost 0, pois o primeiro nó já está encima.
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

/*
Como anteriormente eu não calculei o valor de mandar um nó para outra stack, 
meu total já inicializa com 1.
*/

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
