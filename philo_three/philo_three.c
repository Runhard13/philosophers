/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:25:30 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/15 21:56:29 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	main(int ac, char **av)
{
	t_args	args;
	int		i;

	if (ac < 5 || ac > 6)
		return (print_error("Wrong arguments number\n"));
	if (!parse_args(&args, av, ac) || args.num_of_philos == 0)
		return (print_error("Invalid arguments\n"));
	if (!create_semaphores(&args))
		return (print_error("Semaphore creation failed\n"));
	if (!create_threads(&args))
		return (print_error("Thread creation failed\n"));
	if (!start(&args))
		return (print_error("Simulation start failed\n"));
	sem_wait(args.waiting_for_end);
	i = 0;
	while (i < args.num_of_philos)
		kill(args.philos[i++].pid, SIGKILL);
	free_all(&args);
	return (0);
}
