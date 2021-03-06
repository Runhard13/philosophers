/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:25:30 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/06 18:35:57 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	ft_atoi(const char *str)
{
	size_t	result;
	int		i;
	int		pos;

	i = 0;
	result = 0;
	pos = 1;
	while ((str[i] == ' ') || (str[i] == '\v') || (str[i] == '\t') ||
		   (str[i] == '\f') || (str[i] == '\r') || (str[i] == '\n'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pos = 0;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - 48;
	}
	if (pos)
		return (result);
	else
		return (-result);
}


void parse_args (t_args *args, char **av, int ac)
{
	int i;

	args->num_of_philos = ft_atoi(av[1]);
	args->t_to_die = ft_atoi(av[2]);
	args->t_to_eat = ft_atoi(av[3]);
	args->t_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->num_must_eat = ft_atoi(av[5]);

	i = 0;
	args->philos = (t_philo *)malloc(sizeof(t_philo) * args->num_of_philos);
	while (i < args->num_of_philos)
	{
		args->philos->index = i;
		args->philos->eat_counter = 0;
		i++;
	}
}

void create_mutexes (t_args *args)
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
}

long get_time (void)
{
	struct timeval tv;
	long time;

	gettimeofday(&tv, NULL);
	time = 1000 * tv.tv_sec + tv.tv_usec / 1000;
	return (time);

}


int	main (int ac, char **av)
{
	t_args args;

	if (ac < 5 || ac > 6)
	{
		printf ("Wrong arguments number\n");
		return (0);
	}
	parse_args(&args, av, ac);
}