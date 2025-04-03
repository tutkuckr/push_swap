/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:36:51 by tutku             #+#    #+#             */
/*   Updated: 2025/01/30 22:33:42 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_target_in_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*temp_a;
	t_node	*target_node;
	long	match_index;

	while (stack_b != NULL)
	{
		temp_a = stack_a;
		match_index = LONG_MAX;
		while (temp_a != NULL)
		{
			if (((temp_a->content) > (stack_b->content))
				&& ((temp_a->content) < match_index))
			{
				match_index = temp_a->content;
				target_node = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (match_index != LONG_MAX)
			stack_b->target_node = target_node;
		else
			stack_b->target_node = find_smallest_val(stack_a);
		stack_b = stack_b->next;
	}
}

//Set stack a and b's before median values
//Find `a` node's target in stack `b`
//Set a node's `cheapest` attribute as `true` or `false`
void	set_nodes_of_b(t_node *stack_a, t_node *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	find_target_in_a(stack_a, stack_b);
}
