/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:20:30 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:20:31 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	init_prompt_cycle(t_info *info)
{
	info->error = 0;
	info->index = 0;
	info->tinfo.qstatus = NO_Q;
	info->tinfo.tokenlist = NULL;
	info->tree = NULL;
	info->cmd_count = 1;
	info->input = NULL;
	info->heredoc_offset = 0;
}
