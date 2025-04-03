/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:43:38 by tutku             #+#    #+#             */
/*   Updated: 2025/01/30 22:33:09 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_biggest_val(t_node *stack)
{
	long	biggest_val;
	t_node	*temp;

	if (stack == NULL)
		return (NULL);
	biggest_val = LONG_MIN;
	while (stack != NULL)
	{
		if (stack->content > biggest_val)
		{
			temp = stack;
			biggest_val = stack->content;
		}
		stack = stack->next;
	}
	return (temp);
}

t_node	*find_smallest_val(t_node *stack)
{
	long	smallest_val;
	t_node	*temp;

	if (stack == NULL)
		return (NULL);
	smallest_val = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->content < smallest_val)
		{
			temp = stack;
			smallest_val = stack->content;
		}
		stack = stack->next;
	}
	return (temp);
}

int	find_smallest_position(t_node *stack)
{
	t_node	*current;
	int		smallest;
	int		position;
	int		i;

	if (!stack)
		return (0);
	smallest = stack->content;
	position = 0;
	current = stack;
	i = 0;
	while (current)
	{
		if (current->content < smallest)
		{
			smallest = current->content;
			position = i;
		}
		current = current->next;
		i++;
	}
	return (position);
}
