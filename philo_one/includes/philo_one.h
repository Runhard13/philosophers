/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:23:40 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/08 21:11:45 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_ONE_H
#define PHILOSOPHERS_ONE_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

#define EATING 1
#define THINKING 2
#define SLEEPING 3
#define DIED 4
#define FORK 5

struct s_args;
typedef struct		s_philo
{
	int				index;
	int 			eat_counter;
	long 			last_eat;
	int 			left_fork;
	int 			right_fork;
	long 			death;
	struct s_args	*args;
}					t_philo;

typedef struct		s_args
{
	int				num_of_philos;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				num_must_eat;
	pthread_mutex_t	*forks;
	long 			t_start;
	pthread_mutex_t	who_write;
	pthread_mutex_t	who_dead;
	t_philo			*philos;
}					t_args;


int					check_args(char **av);
int					parse_args(t_args *args, char **av, int ac);
int					create_mutexes (t_args *args);
long				get_time(void);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str);
int					print_error(char *text);
int					create_threads(t_args *args);
char				*ft_itoa(long n);
void				printer(t_philo *philos, int c);
void				take_fork(t_philo *philos);
void				sleeping(t_philo *philos);
void				thinking(t_philo *philos);
void				eat(t_philo *philos);




#endif //PHILOSOPHERS_ONE_H
