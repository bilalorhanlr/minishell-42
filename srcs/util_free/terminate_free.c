/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:20:24 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:20:25 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	iterate_free_tree(t_tree *node)
{
	t_tree	*l_child;
	t_tree	*r_child;

	if (!node)
		return ;
	l_child = node->l_child;
	r_child = node->r_child;
	safety_free((void **)&node->token);
	safety_free((void **)&node);
	iterate_free_tree(l_child);
	iterate_free_tree(r_child);
}

void	free_parse_tree(t_info *info)
{
	t_tree_list	*tree;
	int			i;

	tree = info->tree;
	if (!tree)
		return ;
	i = -1;
	while (++i < info->cmd_count)
		iterate_free_tree(tree[i].root);
	safety_free((void **)&tree);
}

void	free_tokenlist(t_info *info)
{
	t_token	*cur;
	t_token	*temp;

	cur = info->tinfo.tokenlist;
	while (cur)
	{
		temp = cur;
		cur = cur->next;
		safety_free((void **)&temp->token);
		safety_free((void **)&temp->token_origin);
		safety_free((void **)&temp);
	}
}

void	terminate_free(t_info *info)
{
	free_tokenlist(info);
	free_parse_tree(info);
	safety_free((void **)&info->input);
	safety_free((void **)&(info->heredoc));
	return ;
}
