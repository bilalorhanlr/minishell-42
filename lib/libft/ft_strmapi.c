/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:45:35 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 15:45:36 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*k;

	i = 0;
	if (!s)
		return (0);
	k = (char *)malloc(sizeof(char) *(ft_strlen(s) + 1));
	if (!k)
		return (0);
	while (s[i])
	{
		k[i] = f(i, s[i]);
		i++;
	}
	k[i] = '\0';
	return (k);
}
