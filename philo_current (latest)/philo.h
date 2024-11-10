/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:33:06 by brsantsc          #+#    #+#             */
/*   Updated: 2024/11/05 12:11:03 by brsantsc         ###   ########.fr       */
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
	int						id;
	int						meals_eaten;
	int						total_meals;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						time_to_think;
	long long				last_meal_time;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			*print_mutex;
	pthread_mutex_t			meal_time_mutex;
}	t_philo;

typedef struct s_data
{
	int						nbr_of_philos;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						must_eat;
	t_philo					*philos;
	pthread_mutex_t			*forks;
	pthread_mutex_t			print_mutex;
	pthread_t				*threads;
}	t_data;

void			ft_putstr(char *str);
void			mutexes(void *arg);
void			print_status(t_philo *phil, const char *status);
void			init(t_data *data, int argc, char **argv);
void			init_philos(t_data *data);
void			*memory_allocation(size_t mem_size);
void			memory_free(t_data *data);
void			*philos_routine(void *arg);
void			*monitoring_routine(void *arg);
void			precise_sleep(long long duration_in_usec);
void			*memory_alloc(size_t size);
int				all_philos_done(t_data *data);
long			ft_atol(const char *str);
long long		current_time(void);

#endif
