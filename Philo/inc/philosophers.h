/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:15:12 by fsantama          #+#    #+#             */
/*   Updated: 2023/09/20 21:29:42 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*---------------------------------LIBRARIES----------------------------------*/

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

/*-----------------------------------HEADER-----------------------------------*/

# define HEADER ("\n\
\033[36;1m   ____  _   _ ___ _     ___  ____   ___  ____  _   _ _____ ____  ____   \n \
 |  _ )| | | |_ _| |   / _ )( ___| / _ )|  _ )| | | | ____|  _ )( ___|  \n \
 | |_) | |_| || || |  | | | (___ )| | | | |_) | |_| |  _| | |_) |___ )  \n \
 |  __/|  _  || || |__| |_| |___) | |_| |  __/|  _  | |___|  _ < ___) | \n \
 |_|   |_| |_|___|_____(___/|____/ (___/|_|   |_| |_|_____|_|   (____/  \n \
                                                                        \n \
																		\n \
\033[37;1m                         Develop by fsantama                  \n \
\n\033[0m")

/*-----------------------------------ERRORS-----------------------------------*/

# define INVALID_ARGS "Invalid number of arguments, variables:\n \
◦[1] Number of philosophers \n \
◦[2] Time to die (milliseconds) \n \
◦[3] Time to eat (milliseconds)\n \
◦[4] Time to sleep (milliseconds)\n \
◦[5] Number of times each philosopher must eat (OPTIONAL)\n"
# define INVALID_NUMBERS "Arguments must be numbers:\n \
◦[1] Number of philosophers \n \
◦[2] Time to die (milliseconds) \n \
◦[3] Time to eat (milliseconds)\n \
◦[4] Time to sleep (milliseconds)\n \
◦[5] Number of times each philosopher must eat (OPTIONAL)\n"

/*----------------------------------STRUCTS-----------------------------------*/
typedef struct s_table
{
	int	n_philos;
	int	t_dead;
	int	t_eat;
	int	t_sleep;
	int	n_meals;
}	t_table;

typedef struct s_philo
{
	int	id;
}	t_philos;

/*-------------------------------PARSE GENERAL--------------------------------*/
int	ft_check_args(int argc, char **argv, t_table *table, t_philos *philo);

/*-----------------------------------UTILS------------------------------------*/

int	ft_error(char *error);

/*-----------------------------------COLORS-----------------------------------*/
# define BOLD		"\033[1m"
# define BLACK		"\033[30;1m"
# define RED		"\033[31;1m"
# define GREEN		"\033[32;1m"
# define YELLOW		"\033[33;1m"
# define BLUE		"\033[34;1m"
# define MAGENTA	"\033[35;1m"
# define CYAN		"\033[36;1m"
# define WHITE		"\033[37;1m"
# define DEFAULT	"\033[0m"

#endif