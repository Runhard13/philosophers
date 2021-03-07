/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:26:21 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/07 22:02:04 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"



void *philo_routine (void *args)
{

}

int create_threads(t_args *args)
{
	int i;
	pthread_t *thread;
	void *philo;

	i = 0;
	thread = 0;
	args->t_start = get_time();
	while (i < args->num_of_philos)
	{
		philo = (void*)(&args->philos[i]);
		if (pthread_create(thread, NULL, &philo_routine, philo))
			return (0);
		if (pthread_detach(*thread))
			return (0);
		usleep(500);
		i++;
	}
}