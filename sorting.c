/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:22:04 by tutku             #+#    #+#             */
/*   Updated: 2025/02/03 14:11:34 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_node *stack)
{
	if (stack == NULL)
		return (0);
	while (stack->next != NULL)
	{
		if ((stack->content) > (stack->next->content))
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

int	stack_len(t_node *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

void	sort_main(t_node **stack_a, t_node **stack_b)
{
	int		len;

	len = stack_len(*stack_a);
	if (check_if_sorted(*stack_a) == 0)
	{
		if (len == 1)
			return ;
		else if (len == 2)
			swap_a(stack_a);
		if (len == 3)
			sort_three(stack_a);
		else if (len == 4)
			sort_four(stack_a, stack_b);
		else if (len > 4)
			sort_big_stacks(stack_a, stack_b);
	}
}

void	move_smallest(t_node **stack_a, int smallest_pos, int len)
{
	if ((smallest_pos == 3 && len == 4))
		rev_rotate_a(stack_a);
	else
	{
		while (smallest_pos > 0)
		{
			rotate_a(stack_a);
			smallest_pos--;
		}
	}
}
