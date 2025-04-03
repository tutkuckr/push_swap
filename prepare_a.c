/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:36:51 by tutku             #+#    #+#             */
/*   Updated: 2025/01/30 22:25:03 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Set each node's cheapest val as true or false
void	cheapest_node_set(t_node *stack)
{
	t_node	*push_cost_cheapest;
	long	push_cost_val;

	if (stack == NULL)
		return ;
	push_cost_val = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->push_cost < push_cost_val)
		{
			push_cost_cheapest = stack;
			push_cost_val = stack->push_cost;
		}
		stack = stack->next;
	}
	push_cost_cheapest->cheapest = true;
}

// 1. it is below median -> 
//update `a` node's push cost to the stack's length - index
// 2. the target `b` node is above median -> 
//update `a` node's push cost, the sum of 
//(its current index) + (its target `b` node's index)
// 3. `a` node is indeed above median and its 
//target `b` node is below median -> Update `a` node's push cost
static void	cost_analysis_stack_a(t_node *stack_a, t_node *stack_b)
{
	int	length_a;
	int	length_b;

	if (!stack_a || !stack_b)
		return ;
	length_a = stack_len(stack_a);
	length_b = stack_len(stack_b);
	while (stack_a != NULL)
	{
		stack_a->push_cost = stack_a->index;
		if (stack_a->before_median == false)
		{
			stack_a->push_cost = length_a - (stack_a->index);
		}
		if (stack_a->target_node->before_median == true)
		{
			stack_a->push_cost += stack_a->target_node->index;
		}
		else
		{
			stack_a->push_cost += length_b - (stack_a->target_node->index);
		}
		stack_a = stack_a->next;
	}
}

static void	find_target_in_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*temp_b;
	t_node	*target_node;
	long	match_index;

	while (stack_a != NULL)
	{
		temp_b = stack_b;
		match_index = LONG_MIN;
		while (temp_b != NULL)
		{
			if (((temp_b->content) < (stack_a->content))
				&& ((temp_b->content) > match_index))
			{
				match_index = temp_b->content;
				target_node = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (match_index != LONG_MIN)
			stack_a->target_node = target_node;
		else
			stack_a->target_node = find_biggest_val(stack_b);
		stack_a = stack_a->next;
	}
}

void	set_index(t_node *stack)
{
	int	index;
	int	median;

	index = 0;
	if (stack == NULL)
		return ;
	median = stack_len(stack) / 2;
	while (stack != NULL)
	{
		stack->index = index;
		if (index <= median)
			stack->before_median = true;
		else
			stack->before_median = false;
		index++;
		stack = stack->next;
	}
}

//Set stack a and b's before median values
//Find `a` node's target in stack `b`
//Set a node's `cheapest` attribute as `true` or `false`
void	set_nodes_of_a(t_node *stack_a, t_node *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	find_target_in_b(stack_a, stack_b);
	cost_analysis_stack_a(stack_a, stack_b);
	cheapest_node_set(stack_a);
}
