/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:15:31 by brsantsc          #+#    #+#             */
/*   Updated: 2024/10/09 14:35:05 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*memory_allocation(size_t mem_size)
{
	void	*mall_place;

	mall_place = malloc(mem_size);
	if (NULL == mall_place)
		ft_putstr("Error malloc");
	return (mall_place);
}

void	memory_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	free(data->forks);
	free(data->philos);
	free(data->threads);
}
