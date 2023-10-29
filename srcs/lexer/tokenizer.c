/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:19:30 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:19:31 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	tokenizer(t_info *info)
{
	t_token_info	*tinfo;

	tinfo = &info->tinfo;
	tinfo->qstatus = get_qstatus(info->input[info->index], tinfo->qstatus);
	if (tinfo->qstatus == NO_Q
		&& ft_strchr(SEPLIST, info->input[info->index]))
	{
		if (info->input[info->index] == PIPE)
		{
			tinfo->tokenlist = token_add_back(tinfo->tokenlist, PIPE, "|");
			info->cmd_count++;
		}
		else
			redirection_add_back(info);
	}
	string_add_back(info);
}
