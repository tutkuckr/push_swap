/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:34:31 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/02/04 12:07:13 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Error Cases

*Integer Range Check -> from INT_MIN to INT_MAX
*Duplicate Entries -> not allowed
*Empty Input Argument -> empty arg is considered an error
*Must input only nums separated by spaces
*Must skip zeros before numbers -> "2 001" - valid
*Only one sign is allowed -> like normal atoi
*In no parameters case: do not display anything
*/
int	ft_max_atoi(char *nptr)
{
	long	result;
	long	sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		return (-1);
	return (1);
}

int	num_val_check(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 1;
		if (!(ft_isdigit(argv[i][0])
			|| argv[i][0] == '+' || argv[i][0] == '-'))
			return (1);
		if (!(ft_isdigit(argv[i][1]))
			&& (argv[i][0] == '+' || argv[i][0] == '-'))
			return (1);
		while (argv[i][j] != '\0')
		{
			if (!(ft_isdigit(argv[i][j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	double_number_check(char **argv)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			if (num == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	double_sign_check(char **argv)
{
	int	i;
	int	j;
	int	sign_count;

	i = 0;
	while (argv[i])
	{
		j = 0;
		sign_count = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
				sign_count++;
			if (sign_count > 1)
				return (1);
			j++;
		}
		if (sign_count == 1 && ft_strlen(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	input_error_check(char **argv)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	if (num_val_check(argv) || double_sign_check(argv)
		|| double_number_check(argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	while (temp != -1 && argv[i])
	{
		temp = ft_max_atoi(argv[i]);
		i++;
	}
	if (temp == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}
