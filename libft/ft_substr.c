/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:57:10 by tcakir-y          #+#    #+#             */
/*   Updated: 2024/10/16 20:15:31 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	if (!str)
		return (NULL);
	return (str);
}

/*
things to check
1. if length of s is less then the starting index -> return sth to free later
2. if length after the starting point is bigger than the len -> change len 
*/
//int	main(void)
//{
//	char const		*s;
//	unsigned int	start;
//	size_t			len;

//	s = "HELLO! CODAM!";
//	start = 7;
//	len = 7;
//	printf("String: %s", ft_substr(s, start, len));
//	return (0);
//}
