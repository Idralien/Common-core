/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:09:25 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/26 11:22:47 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	remove_quotes(char *str, int i, int j)
{
	int	len;
	int	inside_quotes;

	len = ft_strlen(str);
	inside_quotes = 0;
	while (i < len)
	{
		if ((str[i] == S_QUOTE || str[i] == D_QUOTE) && !inside_quotes)
			inside_quotes = str[i];
		else if (str[i] == S_QUOTE && inside_quotes == S_QUOTE)
			inside_quotes = 0;
		else if (str[i] == D_QUOTE && inside_quotes == D_QUOTE)
			inside_quotes = 0;
		else if (str[i] == SPCE && !inside_quotes)
			break ;
		else
			str[j++] = str[i];
		i++;
	}
	while (i < len)
		str[j++] = str[i++];
	str[j] = NULL_TERM;
}

void	remove_quotes_arr(char **arr, int i)
{
	while (arr[i])
		remove_quotes(arr[i++], 0, 0);
}
