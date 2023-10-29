/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:45:17 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 15:45:18 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"libft.h"

char	*ft_strdup(const char *str)
{
	char	*new_str;
	int		i ;

	i = 0;
	new_str = (char *)malloc(ft_strlen((const char *) str) + 1);
	if (new_str == NULL)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
