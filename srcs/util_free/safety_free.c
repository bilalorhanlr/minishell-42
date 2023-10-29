/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:20:21 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:20:22 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	safety_free(void **data)
{
	if (data && *data)
	{
		free(*data);
		*data = NULL;
	}
}

void	safety_free_doublearray(void ***data)
{
	int	i;

	i = 0;
	if (data)
	{
		while (*data && (*data)[i])
		{
			safety_free((void **)&(*data)[i]);
			i++;
		}
		if (*data)
		{
			free(*data);
			data = NULL;
		}
	}
}
