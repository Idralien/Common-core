/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:42:35 by brsantsc          #+#    #+#             */
/*   Updated: 2024/09/25 14:54:02 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h> //get time of day
#include <pthread.h>
#include <limits.h>
#include <stdbool.h>

# define RESET		"\033[0m"
# define RED			"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE			"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN			"\033[1;36m"
# define WHITE		"\033[1;37m"

/* ./philo 5 800 200 200 [6] 
 * 5 = number of philos
 * 800 = time to die
 * 200 time to eat
 * 200 time to sleep
 * [6] = number of meals*/

typedef	pthread_mutex_t t_mtx;

typedef struct s_table t_table;

typedef struct s_fork
{
	t_mtx	fork;
	int	fork_id;
}		t_fork;

typedef struct s_philo
{
	int	id;
	long	meal_count;
	bool	full;
	long	last_meal;
	t_fork	*left_fork;
	t_fork	*right_fork;
	pthread_t	thread_id; // a philo is a thread
	t_table	*table;
}		t_philo;

struct s_table
{
	long	nbr_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_meals;
	long	start_sim;
	bool	end_sim; // a philo dies or all philos are full
	t_fork	*fork; // array of forks
	t_philo	*philos; // array of philos
};

/*	FUNCTIONS		*/

void	error_exit(const char *error);

#endif
