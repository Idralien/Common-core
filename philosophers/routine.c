/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:48:52 by brsantsc          #+#    #+#             */
/*   Updated: 2024/11/28 12:08:38 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		all_philos_done(t_data *data);
void	mutexes(void *arg);
void	death_check(void *arg);

void	*philos_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		precise_sleep(10);
	while (1)
	{
		mutexes(philo);
		if (philo->total_meals != -1
			&& philo->meals_eaten >= philo->total_meals)
			break ;
	}
	return (NULL);
}

void	*monitoring_routine(void *arg)
{
	t_data		*data;

	data = (t_data *)arg;
	while (1)
	{
		death_check(data);
		if (data->must_eat != -1 && all_philos_done(data))
		{
			printf("Philos ate %d times. Routine finished\n", data->must_eat);
			exit(0);
		}
		usleep(500);
	}
	return (NULL);
}

int	all_philos_done(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philos)
	{
		if (data->philos[i].meals_eaten < data->must_eat)
			return (0);
		i++;
	}
	return (1);
}

void	mutexes(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal_time = current_time();
	pthread_mutex_unlock(&philo->last_meal_mutex);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	print_status(philo, "is sleeping");
	usleep(philo->time_to_sleep * 1000);
	print_status(philo, "is thinking");
}

void	death_check(void *arg)
{
	int			i;
	long long	time_since_last_meal;
	t_data		*data;

	data = (t_data *)arg;
	time_since_last_meal = 0;
	i = 0;
	while (i < data->nbr_of_philos)
	{
		pthread_mutex_lock(&data->philos[i].last_meal_mutex);
		time_since_last_meal = current_time()
			- data->philos[i].last_meal_time;
		pthread_mutex_unlock(&data->philos[i].last_meal_mutex);
		if (time_since_last_meal > data->philos[i].time_to_die)
		{
			pthread_mutex_lock(&data->print_mutex);
			printf("%lld %d died\n", current_time()
				- data->philos[i].start_time, i + 1);
			pthread_mutex_unlock(&data->print_mutex);
			exit(0);
		}
		i++;
	}
}
