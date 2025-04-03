/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:47:43 by tutku             #+#    #+#             */
/*   Updated: 2025/01/30 22:25:17 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dest, char letter)
{
	t_node	*temp;

	if (src == NULL || *src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	temp->prev = NULL;
	if (*dest != NULL)
	{
		temp->next = *dest;
		temp->next->prev = temp;
		*dest = temp;
	}
	else if (*dest == NULL)
	{
		*dest = temp;
		temp->next = NULL;
	}
	ft_printf("p%c\n", letter);
	return ;
}

/*
pa : push a - take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb : push b - take the first element at the top of a and put it at the top of b.
Do nothing if b is empty.
*/