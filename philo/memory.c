/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:02:11 by brsantsc          #+#    #+#             */
/*   Updated: 2024/10/01 12:10:47 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	mem(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_of_philos);
	data->philos = malloc(sizeof(t_philo) * data->nbr_of_philos);
	data->threads = malloc(sizeof(pthread_t) * data->nbr_of_philos);
}

void	mem_free(t_data *data)
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
