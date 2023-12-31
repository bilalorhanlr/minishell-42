/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_envvars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:20:01 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:20:02 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

extern int	g_exit_status;

void	expand_question(t_expand_token *exp_v)
{
	char	*temp;
	char	*num;

	temp = exp_v->str1;
	num = ft_itoa(g_exit_status);
	exp_v->str1 = ft_strjoin(exp_v->str1, num);
	exp_v->i++;
	exp_v->j = exp_v->i + 1;
	safety_free((void **)&temp);
	safety_free((void **)&num);
}

void	expand_critical_case(t_expand_token *exp_v)
{
	char	*temp;

	temp = exp_v->str1;
	exp_v->str1 = ft_strjoin(exp_v->str1, "$");
	exp_v->j = exp_v->i + 1;
	safety_free((void **)&temp);
}

void	expand_remain_string(char *token, t_expand_token *exp_v)
{
	char	*temp;

	temp = exp_v->str1;
	exp_v->str1 = ft_strjoin(exp_v->str1, &token[exp_v->j]);
	safety_free((void **)&temp);
}

void	expand_envvars(char *token, t_expand_token *exp_v, t_env_list *env)
{
	char	*key;
	char	*value;
	char	*temp;

	if (check_dollar_next_question(token, exp_v))
		expand_question(exp_v);
	else if (check_dollar_critical_case(token, exp_v->qstatus, exp_v))
		expand_critical_case(exp_v);
	else
	{
		temp = exp_v->str1;
		key = get_key_in_token(token, exp_v);
		value = get_value_with_key(key, env);
		if (value)
		{
			exp_v->str1 = ft_strjoin(exp_v->str1, value);
			safety_free((void **)&temp);
		}
		if (!ft_strlen(key))
			exp_v->i += 1;
		exp_v->i += ft_strlen(key);
		exp_v->j = exp_v->i + 1;
		safety_free((void **)&key);
		safety_free((void **)&value);
	}
}
