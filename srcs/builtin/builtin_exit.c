/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:18:29 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:18:30 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

static int	flow(long long num, long long sign)
{
	if (sign > 0)
	{
		if (num * sign < 0)
			return (1);
	}
	else
	{
		if (num * sign > 0)
			return (1);
	}
	return (0);
}

static long long	exit_num(char *num)
{
	long long	i;
	long long	neg_sign;
	long long	ret;

	i = 0;
	neg_sign = 1;
	ret = 0;
	if (num[i] == '+' || num[i] == '-')
	{
		if (num[i] == '-')
			neg_sign = -1;
		i++;
	}
	while (num[i] && num[i] >= '0' && num[i] <= '9')
	{
		ret = ret * 10 + num[i++] - '0';
		if (flow(ret, neg_sign))
			return (-1);
	}
	if (num[i])
		return (-1);
	return ((unsigned char)(ret * neg_sign));
}

int	builtin_exit(char **argv, int pipe_flag)
{
	if (argv[1] == NULL)
	{
		if (pipe_flag != 1)
			ft_putendl_fd("exit", 1);
		exit(0);
	}
	if (exit_num(argv[1]) < 0)
	{
		ft_error("exit", argv[0], "numeric argument required");
		exit(255);
	}
	ft_putstr_fd("exit", 1);
	if (argv[2] != NULL)
	{
		ft_error("exit", NULL, "too many arguments");
		exit(1);
	}
	exit(exit_num(argv[1]));
}
