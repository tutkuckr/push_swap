/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:53:00 by tutku             #+#    #+#             */
/*   Updated: 2025/01/06 01:20:18 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
	return ;
}

void	rotate_a(t_node **first)
{
	rotate(first);
	ft_printf("ra\n");
}

void	rotate_b(t_node **first)
{
	rotate(first);
	ft_printf("rb\n");
}

void	rotate_ab(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

/*
ra : rotate a - shift up all elements of stack a by 1. 
The first element becomes the last one.

rb : rotate b - shift up all elements of stack b by 1. 
The first element becomes the last one.

rr : ra and rb at the same time.
*/