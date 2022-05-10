/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:55:37 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/10 15:26:49 by acroisie         ###   ########lyon.fr   */
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
	uint64_t		time_stamp;
	pthread_mutex_t	mtime_stamp;
	pthread_mutex_t	mlast_lunch;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	mnb_lunch;
	void			*mthe_glorious_dead;
	void			*right_fork;
	void			*print_msg;
	int				lfork_st;
	int				*rfork_st;
	int				*the_glorious_dead;
	pthread_t		thread;
	int				nb_of_philos;
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_tepme;
	uint64_t		last_lunch;
	int				nb_lunch;
}t_philo;

typedef struct s_common
{
	pthread_mutex_t	print_msg;
	pthread_mutex_t	mthe_glorious_dead;
	int				the_glorious_dead;
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_tepme;
	t_philo			*philo;
}t_common;

void			ft_usleep(uint64_t ms);
uint64_t		ft_gettime(void);
int				ft_strlen(const char *s);
int				ft_atoi(char const *str);
void			ft_print_msg(t_philo *philo, int msg_id);
int				ft_check_args(char **argv);
int				ft_lets_philo(t_common *data, char **argv);
void			ft_init_data(t_common *data, char **argv);
int				ft_the_glorious_dead(t_philo *philo);
void			ft_destroy_mutex(t_common *data);
int				ft_the_glorious_dead(t_philo *philo);
void			ft_set_death(t_common *data, int i);

#endif