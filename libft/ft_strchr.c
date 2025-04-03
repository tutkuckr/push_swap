/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:50:15 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/17 10:22:13 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		if (s[counter] == (char)c)
		{
			return ((char *)&s[counter]);
		}
		counter++;
	}
	if (s[counter] == (char)c)
		return ((char *)&s[counter]);
	return (0);
}

// int main(void)
// {
// 	const char *c = "a\0";

// 	char *result = ft_strchr(c, '\0');
// 	char *result2 = strchr(c, '\0');
// 	printf("Found character:%ld\n", result - c);
// 	printf("Ft:%s\n", result);
// 	printf("Found character: %ld\n", result2 - c);
// 	printf("Func:%s\n", result);
// 	return (0);
// }
