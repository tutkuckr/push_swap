/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:40:24 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/17 16:42:37 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (n == 0)
		return (dest);
	if (d > s)
	{
		d = (unsigned char *)ft_memmove(dest, src, n);
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

//if they overlap, use memmove (d > s)
//int	main(void)
//{
//	int	source[5] = {1,2,3,4,4};
//	int	destination[5] = {5,6,7,8,9};
//	int	source2[5] = {1,2,3,4,4};
//	int	destination2[5] = {5,6,7,8,9};

//	ft_memcpy(destination, source, sizeof(int)*5);
//	printf("\nResult after ft_memcpy: ");
//	for(int i = 0; i < 5; i++)
//		printf("%d ", destination[i]);
//	printf("\nResult after memcpy: " );
//	memcpy(destination2, source2, sizeof(int)*5);
//	for(int i = 0; i < 5; i++)
//		printf("%d ", destination2[i]);
//	return (0);
//}
