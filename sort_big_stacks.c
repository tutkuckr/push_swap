/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:44:24 by tutku             #+#    #+#             */
/*   Updated: 2025/02/03 13:45:38 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//moves the required node to the top of the stack
//loop until required node is the first node
void	move_node_to_top(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->before_median)
				rotate_a(stack);
			else
				rev_rotate_a(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->before_median)
				rotate_b(stack);
			else
				rev_rotate_b(stack);
		}
	}
}

t_node	*find_cheapest_node(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack != NULL)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

//   rotate_ab 
//loop until stack_a != cheapest(the top node)
//and current stack_b is not stack_a's cheapest node's target node, 
//   rev_rotate_ab
//loop until stack_a != cheapest(the top node)
//and current stack_b is not stack_a's cheapest node's target node, 
void	push_a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	if (!stack_a || !*stack_a)
		return ;
	cheapest = find_cheapest_node(*stack_a);
	if (!cheapest || !cheapest->target_node)
		return ;
	if (cheapest->before_median && cheapest->target_node->before_median)
	{
		while ((*stack_a != cheapest) && (*stack_b != cheapest->target_node))
			rotate_ab(stack_a, stack_b);
	}
	else if (!(cheapest->before_median)
		&& !(cheapest->target_node->before_median))
	{
		while ((*stack_a != cheapest) && (*stack_b != cheapest->target_node))
		{
			rev_rotate_ab(stack_a, stack_b);
		}
	}
	move_node_to_top(stack_a, cheapest, 'a');
	move_node_to_top(stack_b, cheapest->target_node, 'b');
	set_index(*stack_a);
	set_index(*stack_b);
	push(stack_a, stack_b, 'b');
}

void	push_b_to_a(t_node **stack_a, t_node **stack_b)
{
	move_node_to_top(stack_a, (*stack_b)->target_node, 'a');
	push(stack_b, stack_a, 'a');
}

void	sort_big_stacks(t_node **stack_a, t_node **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (!check_if_sorted(*stack_a) && len_a-- > 3)
		push(stack_a, stack_b, 'b');
	if (!check_if_sorted(*stack_a) && len_a-- > 3)
		push(stack_a, stack_b, 'b');
	while (!check_if_sorted(*stack_a) && len_a-- > 3)
	{
		set_nodes_of_a(*stack_a, *stack_b);
		push_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		set_nodes_of_b(*stack_a, *stack_b);
		push_b_to_a(stack_a, stack_b);
	}
	set_index(*stack_a);
	move_node_to_top(stack_a, find_smallest_val(*stack_a), 'a');
}
