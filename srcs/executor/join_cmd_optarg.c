/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_cmd_optarg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:19:11 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:19:12 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

char	*join_cmd_optarg(t_tree *node)
{
	char	*cmdopt;
	char	*temp;

	cmdopt = ft_strdup(node->l_child->token);
	temp = cmdopt;
	cmdopt = ft_strjoin(cmdopt, "\n");
	safety_free((void **)&temp);
	if (node->r_child)
	{
		temp = cmdopt;
		cmdopt = ft_strjoin(cmdopt, node->r_child->token);
		safety_free((void **)&temp);
		temp = cmdopt;
		cmdopt = ft_strjoin(cmdopt, "\n");
		safety_free((void **)&temp);
	}
	return (cmdopt);
}
