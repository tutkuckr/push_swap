/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:27:29 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:00 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	size_t	total_size;

	total_size = nmemb * size;
	if (size == 0 || nmemb == 0)
		return (malloc(1));
	dest = (void *)malloc(total_size);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, total_size);
	return (dest);
}

//int	main(void)
//{
//	int	*arr1;
//	int	*arr2;
//	int	n = 7;

//	arr1 = (int*)calloc(n, sizeof(int));
//	arr2 = (int*)ft_calloc(n, sizeof(int));

//	if (arr1 == NULL)
//	{
//		printf("Memory allocation failed!\n");
//		return (1);
//	}
//	if (arr2 == NULL)
//	{
//		printf("Memory allocation failed!\n");
//		return (1);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr1[i]);// Output: 0 0 0 0 0
//	}
//	printf("\n");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	free(arr1);
//	free(arr2);
//	return (0);
//}
