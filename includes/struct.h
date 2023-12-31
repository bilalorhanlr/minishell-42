/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:17:57 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:17:58 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_env_list
{
	char				*key;
	char				*value;
	char				**split_value;
	struct s_env_list	*next;
}	t_env_list;

typedef struct s_tree
{
	int				type;
	char			*token;
	struct s_tree	*l_child;
	struct s_tree	*r_child;
}	t_tree;

typedef struct s_tree_list
{
	int		fd[2];
	int		prev_fd;
	int		heredoc_offset;
	pid_t	pid;
	t_tree	*root;
}	t_tree_list;

typedef struct s_token
{
	int				tokentype;
	char			*token;
	char			*token_origin;
	struct s_token	*next;
}	t_token;

typedef struct s_token_info
{
	int		qstatus;
	t_token	*tokenlist;
}	t_token_info;

typedef struct s_expand_token
{
	char	*str1;
	char	*str2;
	int		i;
	int		j;
	int		qstatus;
}	t_expand_token;

typedef struct s_parse_util
{
	t_tree	*red_cur;
	t_tree	*cmd_cur;
	char	*temp;
	int		cmd_status;
	int		red_status;
	int		heredoc_status;
	int		heredoc_count;
}	t_parse_util;

typedef struct s_add_env_util
{
	char		*sep;
	char		*key;
	t_env_list	*key_loc;
	t_env_list	*new_env;
}	t_add_env_util;

typedef struct s_heredoc
{
	int	fd[2];
	int	check;
}	t_heredoc;

typedef struct s_info
{
	t_token_info	tinfo;
	t_tree_list		*tree;
	t_env_list		*env_head;
	t_heredoc		*heredoc;
	int				cmd_count;
	char			**envp;
	char			*input;
	int				error;
	int				index;
	int				heredoc_count;
	int				heredoc_offset;
}	t_info;

#endif