/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:25:45 by fsantama          #+#    #+#             */
/*   Updated: 2023/09/28 20:21:05 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	leaks(void)
{
	system("leaks -q philo");
}

void	ft_eat(t_philos *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_l);
		print_mutex(philo, FORK_L);
		pthread_mutex_lock(&philo->fork_r);
		print_mutex(philo, FORK_R);
	}
	else
	{
		pthread_mutex_lock(&philo->fork_r);
		print_mutex(philo, FORK_R);
		if (philo->table->n_philos == 1)
			ft_only_one_philo(philo);
		pthread_mutex_lock(philo->fork_l);
		print_mutex(philo, FORK_L);
	}
	pthread_mutex_lock(&philo->eat);
	philo->l_meal = ft_get_time();
	philo->meals += 1;
	print_mutex(philo, PRINT_EAT);
	pthread_mutex_unlock(&philo->eat);
	usleep(philo->table->t_sleep);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(&philo->fork_r);

}

void	*ft_threads(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	pthread_mutex_lock(&philo->table->stop_mutex);
	while (philo->table->start == 1)
	{
		pthread_mutex_unlock(&philo->table->stop_mutex);
		ft_eat(philo);
//		ft_sleep(philo);
//		ft_think(philo);
		pthread_mutex_lock(&philo->table->stop_mutex);
	}
	pthread_mutex_unlock(&philo->table->stop_mutex);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table		table;
	t_philos	philo[500];
	int			i;

	// atexit(leaks);
	i = -1;
	printf("%s", HEADER);
	if (argc == 5 || argc == 6)
	{
		if (ft_check_args(argc, argv, &table, philo))
			return (1);
		while (++i < table.n_philos)
		{
			if (pthread_create(&philo[i].thread, NULL, ft_threads, &philo[i]))
				return (ft_error(THREAD_ERROR));
		}
	}
	else
		return (ft_error(INVALID_ARGS));
	return (0);
}
