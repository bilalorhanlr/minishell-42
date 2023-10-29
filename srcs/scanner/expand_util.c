/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:20:08 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:20:09 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	find_ds_need_expand(char *token)
{
	int	qstatus;

	qstatus = NO_Q;
	while (*token)
	{
		qstatus = get_qstatus(*token, qstatus);
		if ((qstatus == NO_Q || qstatus == DOUBLE_Q) && *token == '$')
			return (1);
		token++;
	}
	return (0);
}

void	preprocess_expand_ds(char *token, t_expand_token *exp_v)
{
	char	*temp;

	temp = exp_v->str1;
	exp_v->str2 = ft_strndup(&token[exp_v->j], exp_v->i - exp_v->j);
	if (exp_v->str2)
	{
		exp_v->str1 = ft_strjoin(exp_v->str1, exp_v->str2);
		safety_free((void **)&temp);
	}
	safety_free((void **)&exp_v->str2);
}

int	check_dollar_next_question(char *token, t_expand_token *exp_v)
{
	if (token[exp_v->i + 1] == '?')
		return (1);
	return (0);
}

int	check_dollar_critical_case(char *token, int qstatus, t_expand_token *exp_v)
{
	if (ft_strlen(token) == 1
		|| ((*(token + 1 + exp_v->i) == '"') && qstatus == DOUBLE_Q)
		|| (!ft_strncmp(token + exp_v->i, "$\'", 2) && qstatus == DOUBLE_Q))
		return (1);
	else if (!ft_strncmp(token + exp_v->i, "$$", 2) && qstatus != SINGLE_Q)
	{
		exp_v->i++;
		return (1);
	}
	return (0);
}

int	check_quote_need_delete(char c, t_expand_token *exp_v)
{
	if (exp_v->qstatus == NO_Q || exp_v->qstatus == DOUBLE_Q)
	{
		if (c == '\"')
			return (1);
	}
	if (exp_v->qstatus == NO_Q || exp_v->qstatus == SINGLE_Q)
	{
		if (c == '\'')
			return (1);
	}
	return (0);
}
