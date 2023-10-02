/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:25:45 by fsantama          #+#    #+#             */
/*   Updated: 2023/10/02 19:23:37 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	leaks(void)
{
	system("leaks -q philo");
}

void	pthread_finish(t_philos *philo)
{
	int	i;

	i = -1;
	while (++i < philo->table->n_philos)
		pthread_join(philo[i].thread, NULL);
	i = -1;
	while (++i < philo->table->n_philos)
	{
		pthread_mutex_destroy(&philo[i].fork_r);
		pthread_mutex_destroy(&philo[i].eat);
	}
	pthread_mutex_destroy(&philo->table->print);
	pthread_mutex_destroy(&philo->table->stop_mutex);
	free(philo);
}

void	ft_eat(t_philos *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_l);
		print_mutex(philo, PRINT_FORK);
		pthread_mutex_lock(&philo->fork_r);
		print_mutex(philo, PRINT_FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->fork_r);
		print_mutex(philo, PRINT_FORK);
		if (philo->table->n_philos == 1)
			ft_only_one_philo(philo);
		pthread_mutex_lock(philo->fork_l);
		print_mutex(philo, PRINT_FORK);
	}
	pthread_mutex_lock(&philo->eat);
	print_mutex(philo, PRINT_EAT);
	philo->l_meal = ft_get_time();
	philo->meals += 1;
	pthread_mutex_unlock(&philo->eat);
	ft_usleep(philo->table->t_sleep, philo);
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
		print_mutex(philo, PRINT_SLEEP);
		ft_usleep(philo->table->t_sleep, philo);
		if (philo->table->t_sleep == 0)
			usleep(1);
		print_mutex(philo, PRINT_THINK);
		pthread_mutex_lock(&philo->table->stop_mutex);
	}
	pthread_mutex_unlock(&philo->table->stop_mutex);
	pthread_exit(NULL);
}

int	main(int argc, char **argv)
{
	t_table		table;
	t_philos	*philo;
	int			i;

	i = -1;
	printf("%s", HEADER);
	philo = (t_philos *) malloc(sizeof(t_philos) * table.n_philos);
	if (!philo)
		return (1);
	if (argc == 5 || argc == 6)
	{
		if (ft_check_args(argc, argv, &table, philo))
			return (1);
		while (++i < table.n_philos)
		{
			if (pthread_create(&philo[i].thread, NULL, ft_threads, &philo[i]))
				return (ft_error(THREAD_ERROR));
		}
		if (pthread_create(&table.check_dead, NULL, ft_check_dead, philo))
			return (ft_error(THREAD_ERROR));
		pthread_finish(philo);
	}
	else
		return (ft_error(INVALID_ARGS));
	return (0);
}
