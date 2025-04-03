/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:11:53 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/01/30 23:07:41 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a)
{
	int		val1;
	int		val2;
	int		val3;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	val1 = (*stack_a)->content;
	val2 = (*stack_a)->next->content;
	val3 = (*stack_a)->next->next->content;
	if ((val1 > val2) && (val2 < val3) && (val1 < val3))
		swap_a(stack_a);
	else if ((val1 > val2) && (val2 > val3) && (val1 > val3))
	{
		swap_a(stack_a);
		rev_rotate_a(stack_a);
	}
	else if ((val1 > val2) && (val2 < val3) && (val1 > val3))
		rotate_a(stack_a);
	else if ((val1 < val2) && (val2 > val3) && (val3 > val1))
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if ((val1 < val2) && (val2 > val3) && (val1 > val3))
		rev_rotate_a(stack_a);
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int		smallest_pos;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	smallest_pos = find_smallest_position(*stack_a);
	move_smallest(stack_a, smallest_pos, stack_len(*stack_a));
	if (check_if_sorted(*stack_a))
		return ;
	push(stack_a, stack_b, 'b');
	sort_three(stack_a);
	push(stack_b, stack_a, 'a');
}

/*
2,1,3 -> sa
3,2,1 -> sa rra
3,1,2 -> ra
1,3,2 -> sa ra
2,3,1 -> rra
*/
