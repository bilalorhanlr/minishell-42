/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:43:54 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 15:43:55 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
	{
		return (c);
	}
	return (0);
}
