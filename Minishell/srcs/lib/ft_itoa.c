/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 22:30:48 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/26 23:00:08 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_numlen(int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	long	nbr;

	nbr = n;
	len = ft_numlen(nbr);
	if (n < 0)
	{
		len++;
		nbr = -nbr;
	}
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	while (nbr > 0)
	{
		res[len--] = nbr % 10 + 48;
		nbr /= 10;
	}
	if (n < 0)
		res[0] = '-';
	if (n == 0)
		res[0] = '0';
	return (res);
}

char	*ft_strstr(char *big, char *little)
{
	int	i;
	int	j;
	int	l_i;

	i = -1;
	if (!big)
		return (0);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[++i])
	{
		l_i = 0;
		if (big[i] == little[l_i])
		{
			j = i;
			while (big[j] == little[l_i])
			{
				l_i++;
				j++;
				if (little[l_i] == '\0')
					return ((char *)(big + i));
			}
		}
	}
	return (0);
}
