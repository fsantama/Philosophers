/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:33:54 by fsantama          #+#    #+#             */
/*   Updated: 2023/10/02 18:38:25 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_init_table(int argc, char **argv, t_table *table)
{
	table->n_philos = ft_atoi(argv[1]);
	table->t_dead = ft_atoi(argv[2]);
	table->t_eat = ft_atoi(argv[3]);
	table->t_sleep = ft_atoi(argv[4]);
	table->end = 0;
	table->start = 1;
	table->time_start = ft_get_time();
	if (argc == 6)
	{
		table->n_meals = ft_atoi(argv[5]);
		table->end = 1;
	}
}

void	ft_init_philos(t_table *table, t_philos *philo)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		philo[i].id = i + 1;
		philo[i].meals = 0;
		philo[i].l_meal = ft_get_time();
		philo[i].table = table;
		i++;
	}
}
