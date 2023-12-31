/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:17:54 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:17:55 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCANNER_H
# define SCANNER_H

# include "minishell.h"

void	init_expand_token_value(t_expand_token *exp_v);

void	expand_question(t_expand_token *exp_v);
void	expand_critical_case(t_expand_token *exp_v);
void	expand_remain_string(char *token, t_expand_token *exp_v);
void	expand_envvars(char *token, t_expand_token *exp_v, t_env_list *env);

int		find_ds_need_expand(char *token);
void	preprocess_expand_ds(char *token, t_expand_token *exp_v);
int		check_dollar_next_question(char *token, t_expand_token *exp_v);
int		check_dollar_critical_case(char *token, int qstatus,
			t_expand_token *exp_v);
int		check_quote_need_delete(char c, t_expand_token *exp_v);

char	*get_key_in_token(char *token, t_expand_token *exp_v);
char	*get_value_with_key(char *key, t_env_list *env);

void	save_current_string(char *token, t_expand_token *exp_v);
char	*create_expand_result(char *token, t_env_list *env);
char	*delete_quote(char *token);
void	expand_token(t_token *cur, t_env_list *env);
void	expand_tokens(t_info *info);

#endif