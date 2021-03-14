/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:26:21 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/14 21:10:29 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*waiting_for_death(void *args)
{
	t_philo *philos;

	philos = (t_philo*)args;
	while (1)
	{
		sem_wait(philos->eat_or_die);
		if (get_time() > philos->death && !philos->eating)
		{
			printer(philos, DIED);
			sem_post(philos->eat_or_die);
			sem_post(philos->args->waiting_for_end);
			return (NULL);
		}
		sem_post(philos->eat_or_die);
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
			sem_wait(args->philos[i++].eat_sem);
		philos_fed++;
	}
	printer(&args->philos[0], FED);
	sem_post(args->waiting_for_end);
	return (NULL);
}

void	*philo_routine(t_philo *philos)
{
	pthread_t	thread;

	thread = 0;
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
	pthread_t	thread;

	thread = 0;
	if (args->num_must_eat > 0)
	{
		if (pthread_create(&thread, NULL, &waiting_for_fed, (void*)args))
			return (0);
		pthread_detach(thread);
	}
	return (1);
}

int		start(t_args *args)
{
	int		i;

	i = 0;
	args->t_start = get_time();
	while (i < args->num_of_philos)
	{
		args->philos[i].pid = fork();
		if (args->philos[i].pid < 0)
			return (0);
		else if (args->philos[i].pid == 0)
		{
			philo_routine(&args->philos[i]);
			exit(0);
		}
		else
			usleep(100);
		i++;
	}
	return (1);
}