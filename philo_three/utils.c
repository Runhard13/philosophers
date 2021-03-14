/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 21:09:05 by cdrennan          #+#    #+#             */
/*   Updated: 2021/03/14 18:26:13 by cdrennan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(const char *str)
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

char	*ft_itoa(long n)
{
	int		len;
	char	*str;
	long	another_n;

	len = 0;
	another_n = n;
	while (another_n)
	{
		len++;
		another_n /= 10;
	}
	if (!(str = malloc((len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		if (n <= 9 && n >= 0)
		{
			str[len] = (n + 48);
			return (str);
		}
		str[len] = (n % 10 + 48);
		n /= 10;
	}
	return (str);
}

long	get_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = 1000 * tv.tv_sec + tv.tv_usec / 1000;
	return (time);
}

void	free_all(t_args *args)
{
	int		i;
	char *name;
	char *index;

	sem_unlink("ForksSemaphore");
	sem_unlink("WriteSemaphore");
	sem_unlink("WaitingForEnDSemaphore");
	i = 0;
	while (i < args->num_of_philos)
	{
		index = ft_itoa(i);
		name = ft_strjoin("eat_or_die", index);
		sem_unlink(name);
		free(index);
		free(name);
		i++;
	}
	free(args->philos);
}

