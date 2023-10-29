/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:17:44 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:17:45 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEXER_H
# define LEXER_H
# include "struct.h"

void	validate_syntax(t_info *info);

t_token	*create_token(int type, char *str);
t_token	*token_add_back(t_token *token, int type, char *str);
void	string_add_back(t_info *info);
void	redirection_add_back(t_info *info);

int		get_qstatus(char c, int qstatus);
int		check_quote(t_info *info);
int		is_in_charset(char c, const char *charset);
int		is_only_space(char *str);
int		is_redirection(int tokentype);

void	tokenizer(t_info *info);

void	lexer(t_info *info);

#endif