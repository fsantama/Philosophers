/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:09:27 by fsantama          #+#    #+#             */
/*   Updated: 2023/10/02 17:39:54 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_usleep(int t_sleep, t_philos *philo)
{
	int	time;

	time = ft_get_time();
	pthread_mutex_lock(&philo->table->stop_mutex);
	while ((ft_get_time() - time < t_sleep) && philo->table->start)
	{
		pthread_mutex_lock(&philo->table->stop_mutex);
		usleep(10);
		pthread_mutex_unlock(&philo->table->stop_mutex);

	}
	pthread_mutex_unlock(&philo->table->stop_mutex);
}

void	ft_only_one_philo(t_philos *philo)
{
	pthread_mutex_unlock(&philo->fork_r);
	pthread_exit(NULL);
}

void	print_mutex(t_philos *philo, char *message)
{
	int	time;

	pthread_mutex_lock(&philo->table->print);
	time = ft_get_time() - philo->table->time_start;
	pthread_mutex_lock(&philo->table->stop_mutex);
	if (philo->table->start == 1)
		printf("%d Philo %d %s\n", time, philo->id, message);
	pthread_mutex_unlock(&philo->table->stop_mutex);
	pthread_mutex_unlock(&philo->table->print);
}

int	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec) * 1000 + (time.tv_usec / 1000));
}

int	ft_atoi(const char *str)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n);
}