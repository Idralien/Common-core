/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:50:56 by brsantsc          #+#    #+#             */
/*   Updated: 2024/10/11 14:35:47 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_data *data, int argc, char **argv)
{
	int	i;

	data->nbr_of_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		data->must_eat = ft_atol(argv[5]);
	else
		data->must_eat = -1;
	data->philos = malloc(sizeof(t_philo) * data->nbr_of_philos);
	data->forks = malloc(sizeof(pthread_mutex_t)
			* data->nbr_of_philos);
	data->threads = malloc(sizeof(pthread_t) * data->nbr_of_philos);
	i = 0;
	while (i < data->nbr_of_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->print_mutex, NULL);
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philos)
	{
		data->philos[i].id = i;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = current_time();
		data->philos[i].total_meals = data->must_eat;
		data->philos[i].time_to_die = data->time_to_die;
		data->philos[i].time_to_eat = data->time_to_eat;
		data->philos[i].time_to_sleep = data->time_to_sleep;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1)
			% data->nbr_of_philos];
		data->philos[i].print_mutex = &data->print_mutex;
		i++;
	}
}
