/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:55:37 by acroisie          #+#    #+#             */
/*   Updated: 2022/04/19 10:59:57 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h> // To delete
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
}t_philo;

typedef struct s_common
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_tepme;
	t_philo	*philo;
}t_common;

int		ft_strlen(const char *s);
int		ft_atoi(char const *str);
void	ft_putendl_fd(char *s, int fd);
int		check_args(char **argv);
int		lets_philo(t_common *data, char **argv);

#endif