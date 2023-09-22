/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:25:16 by fsantama          #+#    #+#             */
/*   Updated: 2023/09/22 20:28:21 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

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

int	check_table(int argc, char **argv, t_table *table)
{
	ft_init_table(argc, argv, table);
	if (table->n_philos == 0)
		return (ft_error(NO_PHILOS));
	return (0);
}

int	check_philos(char **argv, t_table *table, t_philos *philo)
{
	ft_init_philos(argv, table, philo);
	return (0);
}

int	ft_check_args(int argc, char **argv, t_table *table, t_philos *philo)
{
	if (check_num (argc, argv) != 1)
	{
		if (check_table (argc, argv, table) == 1)
			return (1);
		if (check_philos (argv, table, philo) == 1)
			return (1);
	}
	return (0);
}