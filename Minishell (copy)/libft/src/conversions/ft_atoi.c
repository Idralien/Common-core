/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:45:48 by quvan-de          #+#    #+#             */
/*   Updated: 2024/07/11 12:53:35 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_atoi(const char *str)
{
	char	sign;
	int		i;
	int		result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
