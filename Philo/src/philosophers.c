/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:25:45 by fsantama          #+#    #+#             */
/*   Updated: 2023/09/23 19:18:20 by fsantama         ###   ########.fr       */
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
	int			i;

	atexit(leaks);
	i = -1;
	printf("%s", HEADER);
	if (argc == 5 || argc == 6)
	{
		if (ft_check_args(argc, argv, &table, &philo))
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
