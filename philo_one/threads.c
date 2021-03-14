/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:26:21 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/14 18:40:58 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*waiting_for_death(void *args)
{
	t_philo *philos;

	philos = (t_philo*)args;
	while (1)
	{
		pthread_mutex_lock(&philos->eat_or_die);
		if (get_time() > philos->death && !philos->eating)
		{
			printer(philos, DIED);
			pthread_mutex_unlock(&philos->eat_or_die);
			pthread_mutex_unlock(&philos->args->waiting_for_end);
			return (NULL);
		}
		pthread_mutex_unlock(&philos->eat_or_die);
		usleep(800);
	}
}

void	*waiting_for_fed(void *ar)
{
	t_args	*args;
	int		i;
	int		philos_fed;

	args = (t_args*)ar;
	philos_fed = 0;
	while (philos_fed < args->num_must_eat)
	{
		i = 0;
		while (i < args->num_of_philos)
		{
			pthread_mutex_lock(&args->philos[i].eat_mutex);
			i++;
		}
		philos_fed++;
	}
	printer(&args->philos[0], FED);
	pthread_mutex_unlock(&args->waiting_for_end);
	return (NULL);
}

void	*philo_routine(void *args)
{
	t_philo		*philos;
	pthread_t	thread;

	philos = (t_philo*)args;
	philos->last_eat = get_time();
	philos->death = philos->last_eat + philos->args->t_to_die;
	if (pthread_create(&thread, NULL, &waiting_for_death, philos))
		return (NULL);
	pthread_detach(thread);
	while (1)
	{
		take_fork(philos);
		eat(philos);
		sleeping(philos);
		thinking(philos);
	}
}

int		create_threads(t_args *args)
{
	int			i;
	pthread_t	thread;
	void		*philo;

	args->t_start = get_time();
	i = 0;
	thread = 0;
	if (args->num_must_eat > 0)
		if (pthread_create(&thread, NULL, &waiting_for_fed, (void*)args))
			return (0);
	pthread_detach(thread);
	while (i < args->num_of_philos)
	{
		philo = (void*)(&args->philos[i]);
		if (pthread_create(&thread, NULL, &philo_routine, philo))
			return (0);
		pthread_detach(thread);
		usleep(100);
		i++;
	}
	return (1);
}
