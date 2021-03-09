/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:10:48 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/09 23:03:27 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	check_args(char **av)
{
	int i;
	int j;

	i = 1;
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

int	init_stuff(t_args *args)
{
	int i;

	i = 0;
	while (i < args->num_of_philos)
	{
		args->philos[i].index = i;
		args->philos[i].eat_counter = 0;
		args->philos[i].left_fork = i;
		args->philos[i].right_fork = (i + 1) % args->num_of_philos;
		args->philos[i].args = args;
		args->philos[i].eating = 0;
		if (pthread_mutex_init(&args->philos[i].eat_or_die, NULL))
			return (0);
		if (pthread_mutex_init(&args->philos[i].eat_mutex, NULL))
			return (0);
		pthread_mutex_lock(&args->philos[i].eat_mutex);
		i++;
	}
	return (1);
}

int	parse_args(t_args *args, char **av, int ac)
{
	if (!check_args(av))
		return (0);
	args->num_of_philos = ft_atoi(av[1]);
	args->t_to_die = ft_atoi(av[2]);
	args->t_to_eat = ft_atoi(av[3]);
	args->t_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->num_must_eat = ft_atoi(av[5]);
	if (args->t_to_die < 60 || args->t_to_eat
	< 60 || args->t_to_sleep < 60 || args->num_of_philos > 200)
		return (0);
	if (!(args->philos =
			(t_philo *)malloc(sizeof(t_philo) * args->num_of_philos)))
		return (0);
	if (!init_stuff(args))
		return (0);
	return (1);
}

int	create_semaphores(t_args *args)
{
	int i;

	i = 0;

	while (i < args->num_of_philos)
	{
		if (pthread_mutex_init(&args->forks[i], NULL))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&args->waiting_for_end, NULL))
		return (0);
	pthread_mutex_lock(&args->waiting_for_end);
	if (pthread_mutex_init(&args->write_mutex, NULL))
		return (0);
	return (1);
}
