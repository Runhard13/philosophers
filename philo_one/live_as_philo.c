/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_as_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:45:23 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/14 18:26:13 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	take_fork(t_philo *philos)
{
	pthread_mutex_lock(&philos->args->forks[philos->left_fork]);
	printer(philos, FORK);
	pthread_mutex_lock(&philos->args->forks[philos->right_fork]);
	printer(philos, FORK);
}

void	sleeping(t_philo *philos)
{
	printer(philos, SLEEPING);
	pthread_mutex_unlock(&philos->args->forks[philos->left_fork]);
	pthread_mutex_unlock(&philos->args->forks[philos->right_fork]);
	usleep(philos->args->t_to_sleep * 1000);
}

void	thinking(t_philo *philos)
{
	printer(philos, THINKING);
}

void	eat(t_philo *philos)
{
	pthread_mutex_lock(&philos->eat_or_die);
	philos->eating = 1;
	philos->last_eat = get_time();
	philos->death = philos->args->t_to_die + philos->last_eat;
	printer(philos, EATING);
	usleep(philos->args->t_to_eat * 1000);
	philos->eating = 0;
	philos->eat_counter++;
	pthread_mutex_unlock(&philos->eat_or_die);
	pthread_mutex_unlock(&philos->eat_mutex);
}
