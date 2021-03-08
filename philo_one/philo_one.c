/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:25:30 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/08 22:29:56 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"


int	main (int ac, char **av)
{
	t_args args;

	if (ac < 5 || ac > 6)
		return(print_error("Wrong arguments number\n"));
	if (!parse_args(&args, av, ac) || args.num_of_philos == 0)
		return(print_error("Invalid arguments\n"));
	if (!create_mutexes(&args))
		return (print_error("Mutex creation failed\n"));
	if (!create_threads(&args))
		return (print_error("Mutex creation failed\n"));
	pthread_mutex_lock(&args.waiting_for_death);
	pthread_mutex_unlock(&args.waiting_for_death);
	return (0);

}
