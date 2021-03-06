/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:23:40 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/06 18:22:16 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_ONE_H
#define PHILOSOPHERS_ONE_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct		s_philo
{
	int				index;
	int 			eat_counter;
	long 			last_eat;
	pthread_mutex_t	who_write;
	pthread_mutex_t	who_dead;

}					t_philo;

typedef struct		s_args
{
	int				num_of_philos;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				num_must_eat;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_args;



#endif //PHILOSOPHERS_ONE_H
