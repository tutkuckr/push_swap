/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:36:58 by tutku             #+#    #+#             */
/*   Updated: 2025/01/30 22:28:42 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return ;
}

void	swap_a(t_node **first)
{
	swap(first);
	ft_printf("sa\n");
}

void	swap_b(t_node **first)
{
	swap(first);
	ft_printf("sb\n");
}

void	swap_ab(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

/*
sa: swap a - swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb: swap b - swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss: sa and sb at the same time.
*/