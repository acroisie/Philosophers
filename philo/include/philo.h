/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:55:37 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/04 13:16:26 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	unsigned int	time_stamp;
	pthread_mutex_t	mtime_stamp;
	pthread_mutex_t	mlast_lunch;
	pthread_mutex_t	left_fork;
	void			*right_fork;
	void			*print_msg;
	void			*glorious_dead;
	int				lfork_st;
	int				*rfork_st;
	pthread_t		thread;
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_tepme;
	unsigned int	last_lunch;
	unsigned int	nb_lunch;
}t_philo;

typedef struct s_common
{
	pthread_mutex_t	print_msg;
	pthread_mutex_t	glorious_dead;
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_tepme;
	t_philo			*philo;
}t_common;

void			ft_usleep(long int ms);
unsigned int	ft_gettime(void);
int				ft_strlen(const char *s);
int				ft_atoi(char const *str);
void			ft_print_msg(t_philo *philo, int msg_id);
int				ft_check_args(char **argv);
int				ft_lets_philo(t_common *data, char **argv);
void			ft_init_data(t_common *data, char **argv);

#endif