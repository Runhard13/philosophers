/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_as_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:45:23 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/08 22:00:49 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void take_fork(t_philo *philos)
{
	pthread_mutex_lock(&philos->args->forks[philos->left_fork]);
	printer(philos, FORK);
	pthread_mutex_lock(&philos->args->forks[philos->right_fork]);
	printer(philos, FORK);

}

void sleeping(t_philo *philos)
{
	printer(philos, SLEEPING);
	pthread_mutex_unlock(&philos->args->forks[philos->left_fork]);
	pthread_mutex_unlock(&philos->args->forks[philos->right_fork]);
	usleep(philos->args->t_to_sleep * 1000);
}

void thinking(t_philo *philos)
{
	printer(philos, THINKING);
}

void eat(t_philo *philos)
{
	philos->last_eat = get_time();
	philos->death = philos->args->t_to_die + philos->last_eat;
	printer(philos, EATING);
	usleep(philos->args->t_to_eat * 1000);
	philos->eat_counter++;
}
