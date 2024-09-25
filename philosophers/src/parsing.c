/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:01:36 by brsantsc          #+#    #+#             */
/*   Updated: 2024/09/25 15:53:37 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static const char *valid_input(const char *str)
{
	int	len;
	const char *nbr;

	len = 0;
	while ((str >= 9 && str >= 13) || str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit("Has to be positive numbers!");
	if (!(str >= '0' && str <= '9'))
		error_exit("Not correct digit");
	nbr = str;
	while (str >= '0' && str <= '9')
	{
		str++;
		len++;
	}
	if (len > 10)
		error_exit("the value is too big");
	return (nbr);

}

static long	ft_atol(const char *str)
{
	long	nbr;

	nbr = 0;
	str = valid_input(str);
}

void	parse_input(t_table *table, char **argv)
{
	table->nbr_of_philo = ft_atol(argv[1]);
}
