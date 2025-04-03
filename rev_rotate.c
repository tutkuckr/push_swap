/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:03:26 by tutku             #+#    #+#             */
/*   Updated: 2025/01/30 22:26:46 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_node **stack)
{
	t_node	*second_last;
	t_node	*last;

	second_last = NULL;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack;
	second_last->next = NULL;
	*stack = last;
}

void	rev_rotate_a(t_node **first)
{
	rev_rotate(first);
	ft_printf("rra\n");
}

void	rev_rotate_b(t_node **first)
{
	rev_rotate(first);
	ft_printf("rrb\n");
}

void	rev_rotate_ab(t_node **stack_a, t_node **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
}

/*
/rra : reverse rotate a - shift down all elements of stack a by 1. 
The last element becomes the first one.

rrb : reverse rotate b - shift down all elements of stack b by 1. 
The last element becomes the first one.

rrr : rra and rrb at the same time.
*/