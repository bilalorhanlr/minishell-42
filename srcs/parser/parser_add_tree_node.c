/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add_tree_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:19:51 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:19:52 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

t_tree	*create_node(int type, char *token, t_info *info)
{
	t_tree	*node;

	node = (t_tree *)ft_calloc(1, sizeof(t_tree));
	if (!node)
	{
		info->error = 1;
		return (NULL);
	}
	node->type = type;
	node->token = ft_strdup(token);
	return (node);
}

void	add_red_node(t_tree **parent, char *s, int t, t_info *info)
{
	if ((*parent)->type == ROOT)
	{
		(*parent)->l_child = create_node(BRANCH, "reds branch", info);
		(*parent) = (*parent)->l_child;
		(*parent)->l_child = create_node(BRANCH, "single red branch", info);
		(*parent)->l_child->l_child = create_node(t, s, info);
	}
	else
	{
		(*parent)->r_child = create_node(BRANCH, "reds branch", info);
		(*parent) = (*parent)->r_child;
		(*parent)->l_child = create_node(BRANCH, "single red branch", info);
		(*parent)->l_child->l_child = create_node(t, s, info);
	}
}

void	add_arg_node(t_tree **parent, char *s, int t, t_info *info)
{
	(*parent)->l_child->r_child = create_node(t, s, info);
}

void	add_cmd_node(t_tree **parent, char *s, int t, t_info *info)
{
	(*parent)->r_child = create_node(BRANCH, "cmd branch", info);
	(*parent) = (*parent)->r_child;
	(*parent)->l_child = create_node(t, s, info);
}

void	add_cmd_arg(t_tree **parent, char *s, t_info *info)
{
	char	*temp;

	if ((*parent)->type == BRANCH)
	{
		(*parent)->r_child = create_node(OPTARG, s, info);
		(*parent) = (*parent)->r_child;
	}
	else if ((*parent)->type == OPTARG)
	{
		temp = (*parent)->token;
		(*parent)->token = ft_strjoin((*parent)->token, "\n");
		safety_free((void **)&temp);
		if (s)
		{
			temp = (*parent)->token;
			(*parent)->token = ft_strjoin((*parent)->token, s);
			safety_free((void **)&temp);
		}
	}
}
