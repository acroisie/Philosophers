/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:41:54 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/03 15:43:21 by acroisie         ###   ########lyon.fr   */
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
	// philo->last_lunch = ft_gettimme();
	philo->nb_lunch++;
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
	philo->time_stamp = ft_gettimme();
	philo->nb_lunch = 0;
	if (philo->id % 2)
	{
		ft_print_msg(philo, 4);
		ft_usleep(philo->time_to_eat / 3); // Modify for specific case
	}
	while (1) // !dead
	{
		ft_eat(philo);
		ft_print_msg(philo, 3);
		ft_usleep(philo->time_to_sleep);
		ft_print_msg(philo, 4);
	}
	return ((void *)philo);
}

void	ft_end_check(t_common *data)
{
	int		i;
	long	temp;

	while (1) // !dead
	{
		i = 0;
		while (i < data->nb_of_philos)
		{
			temp = ft_gettimme() - data->philo[i].last_lunch;
			// if (temp >= data->time_to_die)
			// {
			// 	// ft_print_msg(&data->philo[i], 5);
			// 	// exit (30);
			// }
			i++;
		}
	}
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
		ft_end_check(data);
	}
	else
		return (1);
	/* Mutex_join */
	return (0);
}
