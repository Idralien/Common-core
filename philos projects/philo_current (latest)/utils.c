/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:44:20 by brsantsc          #+#    #+#             */
/*   Updated: 2024/11/15 12:07:50 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(char *str)
{
	while (*str)
		write (1, str++, 1);
	write (1, "\n", 1);
}

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_status(t_philo *philo, const char *status)
{
	long long	elapsed_time;

	elapsed_time = current_time() - philo->start_time;
	pthread_mutex_lock(philo->print_mutex);
	printf("%lld %d %s\n", elapsed_time, philo->id + 1, status);
	pthread_mutex_unlock(philo->print_mutex);
}

void	precise_sleep(long long duration)
{
	long long	start_time;

	start_time = current_time();
	while (current_time() - start_time < duration)
	{
		usleep(100);
	}
}

void	philo_cleanup(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
