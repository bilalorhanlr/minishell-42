/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:44:34 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 15:44:35 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const char	*k;
	int			i;

	k = (const char *)ptr;
	i = 0;
	while (n--)
	{
		if (k[i] == (char)c)
		{
			return ((void *)&ptr[i]);
		}
		else
			i++;
	}
	return (0);
}
