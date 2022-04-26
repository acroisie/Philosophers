/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:41:54 by acroisie          #+#    #+#             */
/*   Updated: 2022/04/25 21:39:04 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(philo->print_msg);
	printf("%d %d has taken a fork\n", ft_gettimme(), philo->id);
	pthread_mutex_unlock(philo->print_msg);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->print_msg);
	printf("%d %d has taken a fork\n", ft_gettimme(), philo->id);
	pthread_mutex_unlock(philo->print_msg);
	philo->last_lunch = ft_gettimme();
	pthread_mutex_lock(philo->print_msg);
	printf("%d %d is eating\n", ft_gettimme(), philo->id);
	pthread_mutex_unlock(philo->print_msg);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_think(t_philo *philo)
{
	
}

void	*ft_philo_birth(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!(philo->id % 2))
	{
		while (1)
		{
			ft_eat(philo);
			ft_sleep(philo);
			ft_think(philo);
		}
	}
	else
	{
		while (1)
		{
			ft_think(philo);
			ft_eat(philo);
			ft_sleep(philo);
		}
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
			usleep(1);
			i++;
		}
	}
	else
		return (1);
	/* Mutex_join */
	return (0);
}
