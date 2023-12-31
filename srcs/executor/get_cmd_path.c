/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:19:01 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:19:02 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

char	**get_path_env_list(t_info *info)
{
	t_env_list	*cur;

	cur = info->env_head;
	while (cur)
	{
		if (!ft_strncmp(cur->key, "PATH", 5))
			break ;
		cur = cur->next;
	}
	if (cur)
		return (cur->split_value);
	return (NULL);
}

char	*strjoin_free(char *a, char *b)
{
	char	*temp;

	if (b)
	{
		temp = ft_strjoin(a, b);
		safety_free((void **)&a);
		return (temp);
	}
	return (a);
}

char	*match_cmd_path(char *token, char **path)
{
	struct stat	buf;
	char		*temp;
	int			i;

	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		temp = strjoin_free(temp, token);
		if (!lstat(temp, &buf))
			return (temp);
		safety_free((void **)&temp);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(t_info *info, char *token)
{
	char	*temp;
	char	**path_list;

	if (*token == 0)
		return (NULL);
	temp = NULL;
	path_list = get_path_env_list(info);
	if (!path_list)
	{
		info->error = 1;
		return (temp);
	}
	else
		temp = match_cmd_path(token, path_list);
	return (temp);
}
