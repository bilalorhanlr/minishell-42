/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:18:52 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:18:53 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	input_redir(char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (print_red_error(pathname));
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	output_redir(char *pathname)
{
	int	fd;

	fd = open(pathname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		return (print_red_error(pathname));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	append_redir(char *pathname)
{
	int	fd;

	fd = open(pathname, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		return (print_red_error(pathname));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	heredoc(t_info *info)
{
	int	i;

	i = info->heredoc_offset - 1;
	if (i < 0)
		i = 0;
	while (i < info->heredoc_count && info->heredoc[i].check)
		i++;
	if (dup2(info->heredoc[i].fd[0], STDIN_FILENO) == -1)
		return (130);
	info->heredoc[i].check = 1;
	close(info->heredoc[i].fd[0]);
	return (0);
}

int	execute_redirection(t_info *info, t_tree *node)
{
	if (node->l_child->type == INPUT_R)
		return (input_redir(node->r_child->token));
	else if (node->l_child->type == OUTPUT_R)
		return (output_redir(node->r_child->token));
	else if (node->l_child->type == APPEND_R)
		return (append_redir(node->r_child->token));
	else if (node->l_child->type == HEREDOC)
		return (heredoc(info));
	return (0);
}
