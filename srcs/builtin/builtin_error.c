/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:18:26 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:18:27 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	ft_error(char *cmd, char *cmd_arg, char *errmsg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	if (cmd_arg)
	{
		ft_putstr_fd(cmd_arg, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(errmsg, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_s_quote_error(char *cmd, char *cmd_arg, char *errmsg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("`", 2);
	if (cmd_arg)
		ft_putstr_fd(cmd_arg, 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(errmsg, 2);
	ft_putstr_fd("\n", 2);
}
