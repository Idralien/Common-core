/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:15:31 by brsantsc          #+#    #+#             */
/*   Updated: 2024/10/25 17:46:21 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*memory_alloc(size_t size)
{
	void	*memoc;

	memoc = malloc(size);
	if (NULL == memoc)
		ft_putstr("Error malloc");
	return (memoc);
}

void	memory_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].last_meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	if (data->threads)
		free(data->threads);
}
