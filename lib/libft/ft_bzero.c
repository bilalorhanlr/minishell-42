/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:43:30 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 15:43:31 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*new_str;
	size_t			i;

	new_str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		new_str[i++] = 0;
	}
	s = new_str;
}
