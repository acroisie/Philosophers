/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:55:37 by acroisie          #+#    #+#             */
/*   Updated: 2022/04/16 11:21:48 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h> // To delete
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_common
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}t_common;

int		ft_strlen(const char *s);
int		ft_atoi(char const *str);
void	ft_putendl_fd(char *s, int fd);
int		check_args(char **argv);
void	lets_philo(char **argv);

#endif