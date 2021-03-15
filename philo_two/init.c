/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:10:48 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/15 21:56:29 by cdrennan         ###   ########.fr       */
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

int	make_names_and_sems(t_args *args, int i)
{
	char *index;
	char *name1;
	char *name2;

	index = ft_itoa(i);
	name1 = ft_strjoin("eat_or_die", index);
	name2 = ft_strjoin("eat_count", index);
	if (!index || !name1 || !name2)
		return (0);
	if ((args->philos[i].eat_or_die = ft_sem_open(name1, 1)) == SEM_FAILED)
		return (0);
	if ((args->philos[i].eat_sem = ft_sem_open(name1, 0)) == SEM_FAILED)
		return (0);
	free(index);
	free(name1);
	free(name2);
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
		args->philos[i].args = args;
		args->philos[i].eating = 0;
		if (!make_names_and_sems(args, i))
			return (0);
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
	else
		args->num_must_eat = 0;
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
	if ((args->sem_for_write = ft_sem_open("WriteSemaphore", 1)) == SEM_FAILED)
		return (0);
	if ((args->waiting_for_end =
			ft_sem_open("WaitingForEnDSemaphore", 0)) == SEM_FAILED)
		return (0);
	if ((args->forks =
			ft_sem_open("ForksSemaphore", args->num_of_philos)) == SEM_FAILED)
		return (0);
	return (1);
}
