/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:42:05 by brsantsc          #+#    #+#             */
/*   Updated: 2024/11/28 11:58:38 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int			i;
	t_data		data;
	pthread_t	monitor_thread;

	if (argc < 5 || argc > 6)
		return (ft_putstr("ERROR: Invalid number of arguments"), 1);
	init(&data, argc, argv);
	init_philos(&data);
	data.start_time = current_time();
	pthread_create(&monitor_thread, NULL, monitoring_routine, &data);
	i = 0;
	while (i < data.nbr_of_philos)
	{
		data.philos[i].start_time = data.start_time;
		pthread_create(&data.threads[i], NULL, philos_routine, &data.philos[i]);
		i++;
	}
	i = 0;
	while (i < data.nbr_of_philos)
		pthread_join(data.threads[i++], NULL);
	pthread_join(monitor_thread, NULL);
	memory_free(&data);
	return (0);
}
