/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:25:16 by fsantama          #+#    #+#             */
/*   Updated: 2023/09/18 19:04:27 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	check_num(int argc, char **argv)
{
	int	i;

	i = 0;
}

int	check_table(int argc, char **argv, t_table *table)
{
	
}

int	ft_check_args(int argc, char **argv, t_table *table, t_philos *philo)
{
	if (check_num (argc, argv) == 1)
		return (1);
	if (check_table (argc, argv, table) == 1)
		return (1);
	if (check_philos (argc, argv, philo) == 1)
		return (1);
	return (0);
}