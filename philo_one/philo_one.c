/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:25:30 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/08 18:45:25 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	main (int ac, char **av)
{
	t_args args;

	if (ac < 5 || ac > 6)
		return(print_error("Wrong arguments number\n"));
	if (!parse_args(&args, av, ac))
		return(print_error("Invalid arguments\n"));
	if (!create_mutexes(&args))
		return (print_error("Mutex creation failed\n"));
	if (!create_threads(&args))
		return (print_error("Mutex creation failed\n"));
}
