/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_as_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:45:23 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/07 22:19:45 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void take_fork (t_args *args)
{
	pthread_mutex_lock(&args->forks[args->left_fork]);

}

void printer(t_args *args, int c)
{

	pthread_mutex_lock(&args->philos->who_write);
	print_time;
	print_index;
	print_status;
	timestamp_in_ms X has taken a fork
	pthread_mutex_unlock(&args->philos->who_write);
}


