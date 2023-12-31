/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:18:36 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:18:37 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	check_avaliable_key(char *key)
{
	int	i;

	i = 0;
	if (!key)
		return (0);
	if (!key[i] || (!ft_isalpha(key[i]) && key[i] != '_'))
		return (0);
	i++;
	while (key[i])
	{
		if ((!ft_isalnum(key[i]) && key[i] != '_'))
			return (0);
		i++;
	}
	return (1);
}

void	free_split_value(char **s_val)
{
	int	i;

	i = 0;
	if (!s_val)
		return ;
	while (s_val[i])
	{
		free(s_val[i]);
		i++;
	}
	free(s_val[i]);
	free(s_val);
}

void	delete_env(t_env_list **env_head, char *del_key)
{
	t_env_list	*del_loc;
	t_env_list	*temp;

	del_loc = env_key_location(*env_head, del_key);
	temp = *env_head;
	if (!del_loc)
		return ;
	if (temp == del_loc)
	{
		*env_head = temp->next;
		free(temp->key);
		free(temp->value);
		free_split_value(temp->split_value);
		free(temp);
		return ;
	}
	while (temp->next != del_loc)
		temp = temp->next;
	temp->next = del_loc->next;
	free(del_loc->key);
	free(del_loc->value);
	free_split_value(del_loc->split_value);
	free(del_loc);
}

int	builtin_unset(char **argv, t_env_list *env_head)
{
	int	i;

	i = 0;
	if (argv[1] == NULL)
		return (0);
	while (argv[i])
	{
		if (!check_avaliable_key(argv[i]))
		{
			ft_s_quote_error("unset", argv[i], "not a valid identifier");
			return (1);
		}
		delete_env(&env_head, argv[i]);
		i++;
	}
	return (0);
}
