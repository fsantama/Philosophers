/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:25:16 by fsantama          #+#    #+#             */
/*   Updated: 2023/09/28 19:40:09 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	check_philos(t_table *table, t_philos *philo)
{
	int	i;

	i = -1;
	ft_init_philos(table, philo);
	while (++i < table->n_philos)
	{
		if (pthread_mutex_init(&philo[i].fork_r, NULL))
			return (ft_error(MUTEX_ERROR));
		if (pthread_mutex_init(&philo[i].eat, NULL))
			return (ft_error(MUTEX_ERROR));
		if (i != 0)
			philo[i].fork_l = &philo[i - 1].fork_r;
	}
	if (pthread_mutex_init(&philo->table->print, NULL))
		return (ft_error(MUTEX_ERROR));
	if (pthread_mutex_init(&philo->table->stop_mutex, NULL))
		return (ft_error(MUTEX_ERROR));
	philo[0].fork_l = &philo[i - 1].fork_r;
	return (0);
}

int	check_table(int argc, char **argv, t_table *table)
{
	ft_init_table(argc, argv, table);
	if (table->n_philos == 0)
		return (ft_error(NO_PHILOS));
	if (table->n_philos < 0 || table->t_dead < 0
		|| table->t_eat < 0 || table->t_sleep < 0
		|| table ->n_meals < 0)
		return (ft_error(INVALID_NUMBERS));
	return (0);
}

int	check_num(int argc, char **argv)
{
	int	i;

	i = 0;
	while (--argc > 0)
	{
		i = -1;
		while (argv[argc][++i])
		{
			if (argv[argc][i] < '0' || argv[argc][i] > '9')
				return (ft_error(INVALID_NUMBERS));
		}
	}
	return (0);
}

int	ft_check_args(int argc, char **argv, t_table *table, t_philos *philo)
{
	if (check_num (argc, argv) == 1)
		return (1);
	if (check_table (argc, argv, table) == 1)
		return (1);
	if (check_philos (table, philo) == 1)
		return (1);
	return (0);
}
