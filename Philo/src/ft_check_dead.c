/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:30:59 by fsantama          #+#    #+#             */
/*   Updated: 2023/10/02 19:21:07 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	check_meals(t_philos *philo)
{
	printf("2AQUI\n");
	pthread_mutex_lock(&philo->table->stop_mutex);
	philo->table->start = 0;
	pthread_mutex_unlock(&philo->table->stop_mutex);
	return (1);
}

int	philo_die(t_philos *philo, int *check)
{
	int	i;

	i = -1;
	printf("ENTRO\n");
	while (++i < philo->table->n_philos)
	{
		pthread_mutex_lock(&philo[i].eat);
		printf("%ld\n", ft_get_time() - philo->table->time_start);
		pthread_mutex_lock(&philo->table->stop_mutex);
		if (ft_get_time() - philo[i].l_meal > philo->table->t_dead)
		{
			pthread_mutex_unlock(&philo->table->stop_mutex);
			print_mutex(philo, PRINT_DEAD);
			pthread_mutex_lock(&philo->table->stop_mutex);
			philo->table->start = 0;
			pthread_mutex_unlock(&philo->table->stop_mutex);
			pthread_mutex_unlock(&philo[i].eat);
			return (1);
		}
		pthread_mutex_unlock(&philo->table->stop_mutex);
		if (philo->table->end && philo[i].meals < philo->table->n_meals)
			*check = 0;
		pthread_mutex_unlock(&philo[i].eat);
	}
	printf("AQUI\n");
	return (0);
}

void	*ft_check_dead(void *arg)
{
	int			check;
	t_philos	*philo;
	int			i;

	philo = (t_philos *) arg;
	pthread_mutex_lock(&philo->table->stop_mutex);
	i = 0;
	while (philo->table->start)
	{
		pthread_mutex_unlock(&philo->table->stop_mutex);
		check = 1;
		usleep(10);
		if (philo_die(philo, &check))
		{
			return (NULL);
		}
		printf("ITER: %d\n\n", i++);
		if (philo->table->end && check)
			if (check_meals(philo))
				return (NULL);
		pthread_mutex_lock(&philo->table->stop_mutex);
	}
	pthread_mutex_unlock(&philo->table->stop_mutex);
	return (NULL);
}
