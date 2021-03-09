/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:16:42 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/09 21:19:33 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		print_error(char *text)
{
	write(1, text, ft_strlen(text));
	return (0);
}

void	print_time(t_philo *philos)
{
	char *time_stamp;

	time_stamp = NULL;
	if (!(time_stamp = ft_itoa((get_time() - philos->args->t_start))))
		print_error("Malloc_error");
	write(1, time_stamp, ft_strlen(time_stamp));
	free(time_stamp);
}

void	print_action(int c)
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
	else if (c == FED)
		write(1, "All philopohers fed\n", 20);
}

void	printer(t_philo *philos, int c)
{
	char		*index;
	static int	stop = 0;

	pthread_mutex_lock(&philos->args->write_mutex);
	if (stop != 1)
	{
		if (!(index = ft_itoa(philos->index + 1)))
			print_error("Malloc_error");
		print_time(philos);
		write(1, "   ", 3);
		if (c != FED)
			write(1, index, ft_strlen(index));
		write(1, " ", 1);
		print_action(c);
		if (c == DIED || c == FED)
			stop = 1;
		free(index);
	}
	pthread_mutex_unlock(&philos->args->write_mutex);
}
