/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:20:06 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:20:07 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	save_current_string(char *token, t_expand_token *exp_v)
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
	exp_v->j = exp_v->i + 1;
}

char	*create_expand_result(char *token, t_env_list *env)
{
	t_expand_token	exp_v;

	init_expand_token_value(&exp_v);
	while (token[exp_v.i])
	{
		exp_v.qstatus = get_qstatus(token[exp_v.i], exp_v.qstatus);
		if (check_quote_need_delete(token[exp_v.i], &exp_v))
			save_current_string(token, &exp_v);
		else if ((exp_v.qstatus == NO_Q || exp_v.qstatus == DOUBLE_Q)
			&& token[exp_v.i] == '$')
		{
			preprocess_expand_ds(token, &exp_v);
			expand_envvars(token, &exp_v, env);
		}
		exp_v.i++;
	}
	if (exp_v.i != exp_v.j)
		expand_remain_string(token, &exp_v);
	return (exp_v.str1);
}

char	*delete_quote(char *token)
{
	t_expand_token	exp_v;

	init_expand_token_value(&exp_v);
	while (token[exp_v.i])
	{
		exp_v.qstatus = get_qstatus(token[exp_v.i], exp_v.qstatus);
		if (check_quote_need_delete(token[exp_v.i], &exp_v))
			save_current_string(token, &exp_v);
		exp_v.i++;
	}
	if (exp_v.i != exp_v.j)
		expand_remain_string(token, &exp_v);
	return (exp_v.str1);
}

void	expand_token(t_token *cur, t_env_list *env)
{
	char	*temp;
	char	*temp_origin;

	temp = cur->token;
	temp_origin = cur->token_origin;
	if (cur->tokentype == STR)
	{
		cur->token_origin = delete_quote(cur->token_origin);
		safety_free((void **)&temp_origin);
		if (!find_ds_need_expand(cur->token))
		{
			cur->token = delete_quote(cur->token);
			safety_free((void **)&temp);
			return ;
		}
		cur->token = create_expand_result(cur->token, env);
		safety_free((void **)&temp);
	}
}

void	expand_tokens(t_info *info)
{
	t_token	*cur;

	cur = info->tinfo.tokenlist;
	while (cur)
	{
		expand_token(cur, info->env_head);
		cur = cur->next;
	}
}
