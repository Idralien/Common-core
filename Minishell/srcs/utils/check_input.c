/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:49:01 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/29 19:52:52 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Checks if the input string contains any unclosed 
   single or double quotes. Returns 1 if all quotes 
   are closed, otherwise returns 0. */
int	ft_quote_check(char *input)
{
	int	i;
	int	quote;
	int	dquote;

	i = 0;
	quote = 0;
	dquote = 0;
	while (input[i])
	{
		if (input[i] == '\'' && dquote == 0)
			quote = !quote;
		if (input[i] == '\"' && quote == 0)
			dquote = !dquote;
		i++;
	}
	if (quote == 1 || dquote == 1)
	{
		ft_putstr_fd("Error: quote not closed\n", 1);
		return (0);
	}
	return (1);
}

/* Checks for invalid or incomplete characters in the 
   expander list. Specifically checks for dangling 
   redirection operators and pipes. */
int	check_strange_chars(t_expand *exp)
{
	while (exp)
	{
		if (exp->str && ft_is_redir(exp->str))
		{
			if (!exp->next)
				return ('r');
		}
		if (exp->str && exp->str[0] == '|')
		{
			if (exp->next && exp->next->str && exp->next->str[0] == '|')
				return ('q');
			if (!exp->next)
				return ('x');
		}
		exp = exp->next;
	}
	return (0);
}

/* Frees the memory used by the expander and pipe 
   file descriptors in g_data. Cleans up the blocks 
   after the command execution is finished. */
void	ft_ft_ft(t_data *g_data)
{
	free_exp(g_data->exp);
	free_pipes(g_data->fd_pipe, g_data->block_cnt);
}
