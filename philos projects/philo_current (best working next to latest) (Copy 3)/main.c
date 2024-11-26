/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:42:05 by brsantsc          #+#    #+#             */
/*   Updated: 2024/11/26 11:58:40 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int			i;
	long long		start_time;
	t_data		data;
	pthread_t	monitor_thread;

	if (argc < 5 || argc > 6)
		return (ft_putstr("ERROR: Invalid number of arguments"), 1);
	init(&data, argc, argv);
	init_philos(&data);
	start_time = current_time();
	pthread_create(&monitor_thread, NULL, monitoring_routine, &data);
	i = 0;
	while (i < data.nbr_of_philos)
	{
		data.philos[i].start_time = start_time;
		pthread_create(&data.threads[i], NULL, philos_routine, &data.philos[i]);
		i++;
	}
	i = 0;
	while (i < data.nbr_of_philos)
	{
		printf("Main: Waiting for Philo %d to finish\n", i + 1);
		pthread_join(data.threads[i], NULL);
		printf("Main: Philo %d thread joined\n", i + 1);
		i++;
	}
	pthread_join(monitor_thread, NULL);
	printf("Main: Monitor thread joined\n");
	memory_free(&data);
	return (0);
}
