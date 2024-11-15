/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:44:20 by brsantsc          #+#    #+#             */
/*   Updated: 2024/10/23 16:22:39 by brsantsc         ###   ########.fr       */
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

void	precise_sleep(long long duration_in_usec)
{
	long long	start_time;
	long long	elapsed_time;

	start_time = current_time();
	elapsed_time = 0;
	while (elapsed_time < duration_in_usec)
	{
		elapsed_time = (current_time() - start_time) * 1000;
		usleep(100);
	}
}
