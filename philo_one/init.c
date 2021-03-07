/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:10:48 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/07 21:49:18 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int check_args(char **av)
{
	int i;
	int j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int parse_args(t_args *args, char **av, int ac)
{
	int i;

	if (!check_args(av))
		return(0);
	args->num_of_philos = ft_atoi(av[1]);
	args->t_to_die = ft_atoi(av[2]);
	args->t_to_eat = ft_atoi(av[3]);
	args->t_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->num_must_eat = ft_atoi(av[5]);
	i = 0;
	if (!(args->philos = (t_philo *)malloc(sizeof(t_philo) * args->num_of_philos)))
		return (0);
	while (i < args->num_of_philos)
	{
		args->philos->index = i;
		args->philos->eat_counter = 0;
		args->left_fork = i;
		args->right_fork = (i + 1) % args->num_of_philos;
		i++;
	}
	return (1);
}

int create_mutexes(t_args *args)
{
	int i;

	i = 0;
	args->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * args->num_of_philos);
	while (i < args->num_of_philos)
	{
		pthread_mutex_init(&args->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&args->philos->who_dead, NULL);
	pthread_mutex_init(&args->philos->who_write, NULL);
	return (1);
}
