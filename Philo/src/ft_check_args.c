/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:25:16 by fsantama          #+#    #+#             */
/*   Updated: 2023/09/20 22:13:12 by fsantama         ###   ########.fr       */
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
/*
int	check_table(int argc, char **argv, t_table *table)
{
		
}
*/
int	ft_check_args(int argc, char **argv, t_table *table, t_philos *philo)
{
	(void) philo;
	(void) table;
	if (check_num (argc, argv) != 1)
	{
	//	ft_init_structs()
	//	if (check_table (argc, argv, table) == 1)
	//		return (1);
	//	if (check_philos (argc, argv, philo) == 1)
	//		return (1);	
	return (0);
	}
	return (0);
}