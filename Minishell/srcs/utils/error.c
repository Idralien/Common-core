/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:57:17 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/29 19:54:53 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Handles various error messages based on the 
   type of error encountered, such as command not 
   found, pipe errors, and more. */
static void	ft_error1(char type, t_block *block)
{
	if (type == 'u')
	{
		ft_putstr_fd(block->cmd_name, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (type == 'p')
	{
		ft_putstr_fd(" pipe open error\n", 2);
	}
	else if (type == 'q')
	{
		ft_putstr_fd("I cant handle '||'\n", 2);
	}
	else if (type == 'x')
	{
		ft_putstr_fd("no command after pipe\n", 2);
	}
}

/* Manages additional error messages for cases 
   like memory allocation failure, invalid characters, 
   and missing files after redirection. */
static void	ft_error2(char type)
{
	if (type == 'm')
	{
		ft_putstr_fd("Memory allocation failed\n", 2);
	}
	else if (type == ';' || type == 's')
	{
		ft_putstr_fd("I cant handle ';' or ';;'\n", 2);
	}
	else if (type == '\\')
	{
		ft_putstr_fd("I cant handle '\\'\n", 2);
	}
	else if (type == 'r')
	{
		ft_putstr_fd("No file after redirection\n", 2);
	}
}

/* Central error handling function that delegates 
   specific error messages to the appropriate helper 
   functions based on the error type. */
int	ft_error(char type, t_block *block)
{
	ft_putstr_fd("minishell: ", 2);
	if (type == 'u' || type == 'p' || type == 'q' || type == 'x')
		ft_error1(type, block);
	else if (type == ';' || type == '\\' || type == 'r' || type == 'm')
		ft_error2(type);
	else if (type == 'd')
	{
		ft_putstr_fd(block->cmd_name, 2);
		ft_putstr_fd(": is a directory\n", 2);
		free_blocks(block);
	}
	else if (type == 'e')
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(block->args[1], 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
	return (1);
}

/* Checks for specific control characters in the input 
   string and triggers corresponding error messages 
   if found, like empty quotes or invalid characters. */
int	ft_cntrl(char *input)
{
	if ((input[0] == '\"' && input[1] == '\"') || (input[0] == '\''
			&& input[1] == '\''))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(": command not found\n", 2);
		return (0);
	}
	if (ft_strchr(input, ';') != (char *)0)
	{
		ft_error(';', 0);
		return (0);
	}
	if (ft_strchr(input, '\\') != (char *)0)
	{
		ft_error('\\', 0);
		return (0);
	}
	return (1);
}
