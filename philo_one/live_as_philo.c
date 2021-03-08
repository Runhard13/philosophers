/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_as_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:45:23 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/08 18:45:25 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void take_fork(t_args *args)
{
	pthread_mutex_lock(&args->forks[args->philos->left_fork]);
	printer(args, FORK);
	pthread_mutex_lock(&args->forks[args->philos->right_fork]);
	printer(args, FORK);

}

void sleeping(t_args *args)
{
	printer(args, SLEEPING);
	pthread_mutex_lock(&args->forks[args->philos->left_fork]);
	pthread_mutex_lock(&args->forks[args->philos->right_fork]);
	usleep(args->t_to_sleep * 1000);
}

void thinking(t_args *args)
{
	printer(args, SLEEPING);
	pthread_mutex_lock(&args->forks[args->philos->left_fork]);
	pthread_mutex_lock(&args->forks[args->philos->right_fork]);
}

void eat(t_args *args)
{
	args->philos->last_eat = get_time();
	args->philos->death = args->t_to_die + args->philos->last_eat;
	printer(args, EATING);
	usleep(args->t_to_eat * 1000);
	args->philos->eat_counter++;
}