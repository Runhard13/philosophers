/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:16:42 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/07 22:41:13 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int print_error (char *text)
{
	write(1, text, ft_strlen(text));
	return (0);
}

void print_time(t_args *args)
{
	char *time_stamp;

	time_stamp = ft_itoa((get_time() - args->t_start));
	write(1, time_stamp, ft_strlen(time_stamp));
}

void print_action(int c)
{
	if (c == EATING)
		write(1, "is eating\n", 10);
	else if (c == SLEEPING)
		write(1, "is sleeping\n", 12);
	else if (c == FORK)
		write(1, "has taken a fork\n", 17);
	else if (c == DIED)
		write(1, "is died\n", 8);
	else if (c == THINKING)
		write(1, "is thinking\n", 12);
}

void spamming(t_args *args, int c)
{
	char *index;

	pthread_mutex_lock(&args->philos->who_write);
	index = ft_itoa(args->philos->index +1);
	print_time(args);
	write(1, " ", 1);
	write(1, index, ft_strlen(index));
	write(1, " ", 1);
	print_action(c);
	pthread_mutex_unlock(&args->philos->who_write);
}