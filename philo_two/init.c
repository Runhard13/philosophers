/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:10:48 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/13 18:42:59 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"
#include <errno.h>

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
	char *name;
	char *index;

	i = 0;
	while (i < args->num_of_philos)
	{
		args->philos[i].index = i;
		args->philos[i].eat_counter = 0;
		args->philos[i].args = args;
		args->philos[i].eating = 0;
		index = ft_itoa(i);
		name = ft_strjoin("eat_or_die", index);
		args->philos[i].eat_or_die = sem_open(name, O_CREAT, O_EXCL, 0644, 1);
		free(index);
		free(name);
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
	args->sem_for_write = sem_open("WriteSemaphore", O_CREAT, O_EXCL, 0644, 1);
	printf("sem_for_write - Errno = %d\n", errno);
	args->waiting_for_end = sem_open("WaitingForEnDSemaphore", O_CREAT, O_EXCL, 0644, 0);
	printf("waiting_for_end - Errno = %d\n", errno);
	args->forks = sem_open("ForksSemaphore", O_CREAT, O_EXCL, 0644, args->num_of_philos);
	printf("ForksSemaphore - Errno = %d\n", errno);
	return (1);
}
