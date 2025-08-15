/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:50:28 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/29 19:57:23 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Frees allocated memory for an array of pipe file descriptors.
   Closes each pipe and frees each inner array, then frees the 
   outer array itself. */
void	free_pipes(int **pipefd, int cnt)
{
	int	i;

	i = 0;
	if (!pipefd)
		return ;
	while (i < cnt)
	{
		if (pipefd[i])
		{
			close(pipefd[i][0]);
			close(pipefd[i][1]);
			free(pipefd[i]);
		}
		i++;
	}
	free(pipefd);
}

/* Frees the memory allocated for a single string. */
void	free_string(char *str)
{
	if (str)
		free(str);
}

/* Frees an array of strings, deallocating each string
   individually before freeing the array itself. */
void	free_matrix(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		free (str[i]);
	free(str);
	str = NULL;
}

/* Frees memory for a t_block structure, including its 
   command name and arguments. */
void	free_blocks(t_block *blocks)
{
	if (!blocks)
		return ;
	free_string(blocks->cmd_name);
	free_matrix(blocks->args);
	free(blocks);
}

/* Frees a linked list of t_expand structures, deallocating 
   the string and the structure for each node. */
void	free_exp(t_expand *exp)
{
	t_expand	*tmp;

	if (!exp)
		return ;
	while (exp)
	{
		tmp = exp;
		exp = exp->next;
		free(tmp->str);
		free(tmp);
	}
}
