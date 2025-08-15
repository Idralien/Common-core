/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:47:44 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/06 16:48:03 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	nbr;
	int	isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (s[i] != '\0' && (s[i] == 32 || s[i] == '\t' || s[i] == '\n'
			|| s[i] == '\r' || s[i] == '\v' || s[i] == '\f'))
		i++;
	if (s[i] != '\0' && s[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] != '\0' && ft_isdigit(s[i]))
		nbr = (nbr * 10) + (s[i++] - '0');
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}
