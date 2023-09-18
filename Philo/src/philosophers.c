/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:25:45 by fsantama          #+#    #+#             */
/*   Updated: 2023/09/18 19:09:23 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	leaks(void)
{
	system("leaks -q philo");
}

int	main(int argc, char **argv)
{
	t_table		table;
	t_philos	philo;

	atexit(leaks);
	printf("%s", HEADER);
	if (argc == 5 || argc == 6)
	{
		ft_check_args(argc, argv, table, philo);
	}
	else
		return (printf("%s", INVALID_ARGS));
	return (0);
}
