/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:17:36 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:17:37 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUILTIN_H
# define BUILTIN_H
# include "minishell.h"

int			builtin_cd(char **path, t_info *info);
int			builtin_echo(char **argv);
int			builtin_env(char **argv, t_env_list *env_head);
int			builtin_exit(char **argv, int pipe_flag);
int			builtin_export(char **argv, t_info *info);
int			builtin_pwd(void);
int			builtin_unset(char **argv, t_env_list *env_head);

/* BUILTIN ERROR */
void		ft_error(char *cmd, char *cmd_arg, char *errmsg);
void		ft_s_quote_error(char *cmd, char *cmd_arg, char *errmsg);

/* UNSET FUNCTION */
int			check_avaliable_key(char *key);
void		free_split_value(char **s_val);

/* BUILTIN UTILS */
t_env_list	*new_env_list(char *argv, int del);
void		env_add_back(t_env_list **env_list, t_env_list *new);
void		update_env_val(t_env_list *key_loc, char *sep, int del);
t_env_list	*env_key_location(t_env_list *env_head, char *key);

#endif
