/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:32:58 by dteruya           #+#    #+#             */
/*   Updated: 2025/03/11 17:31:04 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack_node
{
	int					value;
	int					push_a;
	int					push_b;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*next;
}	t_stack_node;

//init stack
void			stack_init(t_stack_node **a, char **argv, bool flag_argc_2);
int				error_syntax(char *str);
void			free_error(t_stack_node **a, char **argv, bool flag_argc_2);
int				error_duplicate(t_stack_node *a, int nbr);
void			free_matrix(char **argv);

//manipulate node
void			append_node(t_stack_node **stack, int nbr);
t_stack_node	*new_node(int content);
void			add_back(t_stack_node **stack, t_stack_node *node);
void			free_stack(t_stack_node **stack);
t_stack_node	*last_node(t_stack_node **stack);

//manipulate stack
int				stack_len(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);

//swap move
void			swap_stack(t_stack_node **stack, char c);

#endif
