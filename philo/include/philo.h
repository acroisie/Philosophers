/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:55:37 by acroisie          #+#    #+#             */
/*   Updated: 2022/04/20 11:33:28 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h> // To delete
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	void			*common;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
}t_philo;

typedef struct s_common
{
	int		nb_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_of_tepme;
	t_philo	*philo;
}t_common;

void			ft_usleep(long int ms);
unsigned int	ft_gettimme(void);
int				ft_strlen(const char *s);
int				ft_atoi(char const *str);
void			ft_putendl_fd(char *s, int fd);
int				ft_check_args(char **argv);
int				ft_lets_philo(t_common *data, char **argv);

#endif