/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:45:48 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 15:45:49 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*str2 == '\0' || str2 == NULL)
		return ((char *) str1);
	while (str1[i] != '\0' && i < n)
	{
		j = 0;
		while (str2[j] == str1[i + j] && i + j < n)
		{
			if (str2[j + 1] == '\0')
			{
				return ((char *)str1 + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
