/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:23:40 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/16 00:37:23 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>

# define EATING 1
# define THINKING 2
# define SLEEPING 3
# define DIED 4
# define FORK 5
# define FED 6

struct s_args;
typedef struct		s_philo
{
	int				index;
	int				eating;
	int				eat_counter;
	long			death;
	long			last_eat;
	sem_t			*eat_or_die;
	sem_t			*eat_sem;
	struct s_args	*args;
}					t_philo;

typedef struct		s_args
{
	int				num_of_philos;
	long			t_to_die;
	long			t_to_eat;
	long			t_to_sleep;
	int				num_must_eat;
	long			t_start;
	sem_t			*forks;
	sem_t			*sem_for_write;
	sem_t			*waiting_for_end;
	t_philo			*philos;
}					t_args;
int					check_args(char **av);
int					parse_args(t_args *args, char **av, int ac);
int					create_semaphores(t_args *args);
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
void				free_all(t_args *args);
char				*ft_strjoin(char const *s1, char const *s2);
sem_t				*ft_sem_open(char *name, int value);
void				ft_usleep(long length);
#endif
