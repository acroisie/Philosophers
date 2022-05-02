/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:41:54 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/02 16:40:47 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	philo->lfork_st = 0;
	ft_print_msg(philo, 1);
	pthread_mutex_lock(philo->right_fork);
	*philo->rfork_st = 0;
	ft_print_msg(philo, 1);
	philo->last_lunch = ft_gettimme(); // To modify
	ft_print_msg(philo, 2);
	ft_usleep(philo->time_to_eat);
	*philo->rfork_st = 1;
	pthread_mutex_unlock(philo->right_fork);
	philo->lfork_st = 1;
	pthread_mutex_unlock(&philo->left_fork);
}

void	*ft_philo_birth(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
	{
		ft_print_msg(philo, 4);
		ft_usleep(philo->time_to_eat / 3);
	}
	while (1)
	{
		ft_eat(philo);
		ft_print_msg(philo, 3);
		ft_usleep(philo->time_to_sleep);
		ft_print_msg(philo, 4);
	}
	return ((void *)philo);
}

int	ft_lets_philo(t_common *data, char **argv)
{
	int	i;

	i = 0;
	ft_init_data(data, argv);
	if (data->philo)
	{
		while (i < data->nb_of_philos)
		{
			pthread_create(&data->philo[i].thread, NULL, \
			ft_philo_birth, &data->philo[i]);
			i++;
		}
		// Check death around here
	}
	else
		return (1);
	/* Mutex_join */
	return (0);
}
