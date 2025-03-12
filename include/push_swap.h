/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:32:58 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/12 13:41:31 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int					value;
	int					push_a;
	int					push_b;
	bool				above_median;
	bool				cheapest;
	struct s_stack	*next;
}	t_stack;

//init stack
void	stack_init(t_stack **a, char **argv, bool flag_argc_2);
int		error_syntax(char *str);
void	free_error(t_stack **a, char **argv, bool flag_argc_2);
int		error_duplicate(t_stack *a, int nbr);
void	free_matrix(char **argv);

//manipulate node
void	append_node(t_stack **stack, int nbr);
t_stack	*new_node(int content);
void	add_back(t_stack **stack, t_stack *node);
void	free_stack(t_stack **stack);
t_stack	*last_node(t_stack *stack);
t_stack	*prev_last_node(t_stack *stack);

//manipulate stack
int		stack_len(t_stack *stack);
bool	stack_sorted(t_stack *stack);

//swap move
void	swap_stack(t_stack **stack, char c);
void	swap(t_stack **stack);
void	rotate_stack(t_stack **stack, char c);
void	rotate(t_stack **stack);
void	rev_rotate_stack(t_stack **stack, char a);
void	rev_rotate(t_stack **stack);

void	tiny_sort(t_stack **stack);
t_stack	*find_biggest(t_stack *a);

#endif
