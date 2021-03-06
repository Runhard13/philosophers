/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_as_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:45:23 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/15 21:56:29 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	take_fork(t_philo *philos)
{
	sem_wait(philos->args->forks);
	printer(philos, FORK);
	sem_wait(philos->args->forks);
	printer(philos, FORK);
}

void	sleeping(t_philo *philos)
{
	printer(philos, SLEEPING);
	sem_post(philos->args->forks);
	sem_post(philos->args->forks);
	ft_usleep(philos->args->t_to_sleep);
}

void	thinking(t_philo *philos)
{
	printer(philos, THINKING);
}

void	eat(t_philo *philos)
{
	sem_wait(philos->eat_or_die);
	philos->eating = 1;
	philos->last_eat = get_time();
	philos->death = philos->args->t_to_die + philos->last_eat;
	printer(philos, EATING);
	ft_usleep(philos->args->t_to_eat);
	philos->eating = 0;
	philos->eat_counter++;
	sem_post(philos->eat_sem);
	sem_post(philos->eat_or_die);
}
