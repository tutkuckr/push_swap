/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:45:45 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/02/04 10:09:36 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				content;
	int				index;
	int				push_cost;
	bool			before_median;
	bool			cheapest;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target_node;
}					t_node;

// Input Checkers
int		input_error_check(char **argv);
int		num_val_check(char **argv);
int		double_number_check(char **argv);
int		double_sign_check(char **argv);
int		ft_max_atoi(char *nptr);
void	print_list(t_node *lst);

// Rules
void	swap(t_node **stack);
void	swap_a(t_node **first);
void	swap_b(t_node **first);
void	swap_ab(t_node **stack_a, t_node **stack_b);

void	rotate(t_node **stack);
void	rotate_a(t_node **first);
void	rotate_b(t_node **first);
void	rotate_ab(t_node **stack_a, t_node **stack_b);

void	rev_rotate(t_node **stack);
void	rev_rotate_a(t_node **first);
void	rev_rotate_b(t_node **first);
void	rev_rotate_ab(t_node **stack_a, t_node **stack_b);

void	push(t_node **src, t_node **dest, char letter);

// Linked List - push_swap.c
int		stack_create(t_node **stack_a, char **args);
t_node	*add_back(t_node **stack_a, int num);
int		stack_len(t_node *stack);

// ft_free
void	ft_free_split(char **split);
void	ft_free_stack(t_node **stack);

// Sorting Functions
void	sort_main(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack_a);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_big_stacks(t_node **stack_a, t_node **stack_b);
void	move_smallest(t_node **stack_a, int smallest_pos, int len);
int		check_if_sorted(t_node *stack);

// Prepare a
void	set_nodes_of_a(t_node *stack_a, t_node *stack_b);
void	set_index(t_node *stack);
void	cheapest_node_set(t_node *stack);

// Prepare b
void	set_nodes_of_b(t_node *stack_a, t_node *stack_b);

// Find smallest and biggest node
t_node	*find_biggest_val(t_node *stack);
t_node	*find_smallest_val(t_node *stack);
int		find_smallest_position(t_node *stack);

// Sort big stacks
void	push_a_to_b(t_node **stack_a, t_node **stack_b);
void	push_b_to_a(t_node **stack_a, t_node **stack_b);
void	move_node_to_top(t_node **stack, t_node *top_node, char stack_name);
t_node	*find_cheapest_node(t_node *stack);
#endif
