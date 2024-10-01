/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:33:06 by brsantsc          #+#    #+#             */
/*   Updated: 2024/10/01 12:11:33 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define RESET			"\033[0m"
# define RED			"\033[1;31m"
# define GREEN			"\033[1;32m"
# define YELLOW			"\033[1;33m"
# define BLUE			"\033[1;34m"
# define MAGENTA		"\033[1;35m"
# define CYAN			"\033[1;36m"
# define WHITE			"\033[1;37m"

typedef struct s_philo
{
	int	id;
	int	meals_eaten;
	long long last_meal_time;
	int	total_meals;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print_mutex;
}	t_philo;

typedef struct s_data
{
	int	nbr_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	t_philo	*philos;
	pthread_t	*threads;
}	t_data;

void	ft_putstr(char *str);
void	mem(t_data *data);
void	mem_free(t_data *data);

#endif
