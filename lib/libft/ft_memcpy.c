/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:44:40 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 15:44:41 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*k ;
	const char		*s;
	int				i;

	k = (unsigned char *)dest;
	s = (const char *)src;
	i = 0;
	if (s == NULL && k == NULL)
		return (NULL);
	while (n--)
	{
		k[i] = s[i];
		i++;
	}
	dest = k;
	return (dest);
}
