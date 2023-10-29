/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:17:52 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:17:53 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSER_H
# define PARSER_H
# include "minishell.h"

void	init_tree_with_pipecount(t_info *info);
void	init_parse_util(t_parse_util *par_v, t_tree *root);

t_tree	*create_node(int type, char *token, t_info *info);
void	add_cmd_arg(t_tree **parent, char *s, t_info *info);
void	add_cmd_node(t_tree **parent, char *s, int t, t_info *info);
void	add_arg_node(t_tree **parent, char *s, int t, t_info *info);
void	add_red_node(t_tree **parent, char *s, int t, t_info *info);

void	build_tree(t_info *info);

#endif