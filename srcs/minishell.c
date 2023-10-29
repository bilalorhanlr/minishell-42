/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:20:34 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:20:37 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	terminate_arg(int argc, char **argv)
{
	if (!argv)
		argc += 1;
	argc = (int)argc;
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	terminate_arg(argc, argv);
	set_signal();
	init_info(&info, envp);
	prompt(&info);
	return (0);
}
