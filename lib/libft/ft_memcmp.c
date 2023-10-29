/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:44:37 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 15:44:38 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	const unsigned char	*k;
	const unsigned char	*j;
	size_t				i ;

	i = 0;
	k = (const unsigned char *)ptr1;
	j = (const unsigned char *)ptr2;
	while (n--)
	{
		if (k[i] == j[i])
		{
			i++;
		}
		else
			return (-(j[i] - k[i]));
	}
	return (0);
}
