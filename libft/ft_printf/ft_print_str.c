/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:36:25 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/30 10:01:41 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*De reden waarom er (null) moet staan is omdat met () het word aanzien als 
een null pointer, als deze haakjes er niet staan dan word het gezien als
een gewone string die geschreven moet worden*/

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i] != '\0')
		i++;
	ft_putstr_fd(str, 1);
	return (i);
}
