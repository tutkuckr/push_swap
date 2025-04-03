/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:52:25 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/02/03 15:55:06 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_list(t_node *lst)
// {
// 	ft_printf("---\n");
// 	while (lst)
// 	{
// 		ft_printf("%d ", lst -> content);
// 		lst = lst -> next;
// 	}
// 	ft_printf("\n---");
// }

int	stack_create(t_node **stack_a, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (input_error_check(args))
			return (-1);
		*stack_a = add_back(stack_a, ft_atoi(args[i]));
		i++;
	}
	return (1);
}

t_node	*add_back(t_node **stack_a, int num)
{
	t_node	*end_of_list;
	t_node	*new_add;

	new_add = (t_node *)malloc(sizeof(t_node));
	if (!new_add)
		return (NULL);
	new_add -> content = num;
	new_add -> next = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = new_add;
		return (*stack_a);
	}
	end_of_list = *stack_a;
	while (end_of_list -> next != NULL)
		end_of_list = end_of_list -> next;
	end_of_list -> next = new_add;
	return (*stack_a);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		split;
	int		result_stack_create;

	stack_a = NULL;
	stack_b = NULL;
	split = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		split = 1;
		result_stack_create = stack_create(&stack_a, argv);
	}
	else
		result_stack_create = stack_create(&stack_a, (argv + 1));
	if (result_stack_create != -1)
		sort_main(&stack_a, &stack_b);
	if (split == 1)
		ft_free_split(argv);
	ft_free_stack(&stack_a);
	return (0);
}
