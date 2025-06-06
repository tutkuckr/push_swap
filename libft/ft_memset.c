/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:46:20 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/10 14:36:49 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			counter;

	ptr = (unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		ptr[counter] = (unsigned char)c;
		counter++;
	}
	return (s);
}
//ft_memset()
//memset() is used to fill a block of memory with a particular value.
//
//int	main(void)
//{
//	char	chr1[6];
//	char	chr2[6];
//	int		i;

//	i = 0;
//	ft_memset(chr1, 'X', sizeof(chr1));
//	memset(chr2, 'X', sizeof(chr2));
//	printf("ft_memset: ");
//	for (i = 0; i < 6; i++)
//	{
//        printf("%c ", chr1[i]);
//   }
//	printf("\n memset: ");
//	for (i = 0; i < 6; i++)
//	{
//        printf("%c ", chr2[i]);
//    }
//	return (0);
//}
