/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:48:52 by brsantsc          #+#    #+#             */
/*   Updated: 2024/11/15 12:13:31 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_philos_done(t_data *data);
void	mutexes(void *arg);
void	forks(void *arg);

void	*philos_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(5000);
	while (1)
	{
		print_status(philo, "is thinking");
//		forks(philo);
		mutexes(philo);
		if (philo->total_meals != -1
			&& philo->meals_eaten >= philo->total_meals)
			break ;
	}
	return (NULL);
}

void	*monitoring_routine(void *arg)
{
	int			i;
	long long	time_since_last_meal;
	t_data		*data;

	data = (t_data *)arg;
	time_since_last_meal = 0;
		while (1)
	{
		i = 0;
		while (i < data->nbr_of_philos)
		{
			pthread_mutex_lock(&data->philos[i].meal_time_mutex);
			time_since_last_meal = current_time()
				- data->philos[i].last_meal_time;
			if (time_since_last_meal > data->philos[i].time_to_die)
			{
				print_status(&data->philos[i], "died");
//				pthread_mutex_unlock(&data->philos[i].meal_time_mutex);
				exit(0);
			}
			pthread_mutex_unlock(&data->philos[i].meal_time_mutex);
			i++;
		}
		if (data->must_eat != -1 && all_philos_done(data))
		{
			printf("Philos ate %d times. Routine finished\n", data->must_eat);
			exit(0);
		}
		usleep(1000);
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
	pthread_mutex_lock(&philo->meal_time_mutex);
	philo->last_meal_time = current_time();
	pthread_mutex_unlock(&philo->meal_time_mutex);
	usleep(philo->time_to_eat * 1000);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	print_status(philo, "is sleeping");
	usleep(philo->time_to_sleep * 1000);
}

/*void	forks(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork", philo->time_to_die);
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork", philo->time_to_die);
		pthread_mutex_lock(philo->left_fork);
	}
}*/
