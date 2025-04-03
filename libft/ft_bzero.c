/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:35:38 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/11 16:29:20 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			counter;

	counter = 0;
	ptr = (unsigned char *)s;
	while (counter < n)
	{
		ptr[counter] = 0;
		counter++;
	}
}

//ft_bzero()
//bzero() is a function in C that sets a block of memory to zero. 
//It's typically used to clear out memory buffers.
//int	main(void)
//{
//	char chr1[] = "HELLO WORLD";
//	char chr2[] = "HELLO WORLD";
//	printf("BEFORE : ");
//	printf("%s\n", chr1);
//	printf("BEFORE : ");
//	printf("%s\n", chr2);
//	ft_bzero(chr1, 2);
//	bzero(chr2, 2);
//	printf("\nft: ");
//    printf("%s\n", &chr1[2]);
//	printf("\nFUNCTION: ");
//    printf("%s ", &chr2[2]);
//	return (0);
//}
