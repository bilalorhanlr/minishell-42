/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bilalorhanlar <bilalorhanlar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:17:38 by bilalorhanl       #+#    #+#             */
/*   Updated: 2023/10/29 16:17:39 by bilalorhanl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONSTANT_H
# define CONSTANT_H

# define SEPLIST "<>| "
# define SPACELIST " \t\n\v\f\r"
# define METACHARACTER "<>| \t\n\v\f\r"
# define UNCLOSED_QUOTE "bash : Unclosed quote detected"
# define SYNTAX_ERROR_PRE "minishell: syntax error near unexpected token `"

typedef enum e_cmd_type
{
	ROOT = 0,
	STR = 1,
	INPUT_R = 2,
	OUTPUT_R = 3,
	APPEND_R = 4,
	HEREDOC = 5,
	CMD = 6,
	OPTARG = 7,
	BRANCH = 8,
}	t_cmd_type;

typedef enum e_builtin_cmd
{
	CMD_CD = 1,
	CMD_PWD = 2,
	CMD_ENV = 3,
	CMD_ECHO = 4,
	CMD_EXIT = 5,
	CMD_UNSET = 6,
	CMD_EXPORT = 7,
}	t_builtin_cmd;

typedef enum e_token_type
{
	DOUBLE_Q = '"',
	SINGLE_Q = '\'',
	NO_Q = -1,
	LEFT_ANGLE = '<',
	RIGHT_ANGLE = '>',
	DOLLAR = '$',
	PIPE = '|',
	BACK_SLASH = '\\',
	GRAVE = '`',
	SP = ' ',
	NL = '\n',
}	t_token_type;

#endif