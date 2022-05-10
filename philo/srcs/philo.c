/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:41:54 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/10 15:51:16 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	philo->lfork_st = 0;
	ft_print_msg(philo, 1);
	if (philo->nb_of_philos > 2)
	{
		pthread_mutex_lock(philo->right_fork);
		*philo->rfork_st = 0;
		ft_print_msg(philo, 1);
		pthread_mutex_lock(&philo->mlast_lunch);
		philo->last_lunch = ft_gettime();
		pthread_mutex_unlock(&philo->mlast_lunch);
		ft_print_msg(philo, 2);
		ft_usleep(philo->time_to_eat);
		philo->lfork_st = 1;
		pthread_mutex_unlock(&philo->left_fork);
		*philo->rfork_st = 1;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(&philo->mnb_lunch);
		philo->nb_lunch++;
		pthread_mutex_unlock(&philo->mnb_lunch);
	}
	else
		ft_usleep(philo->time_to_die);
}

void	*ft_philo_birth(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->mlast_lunch);
	philo->last_lunch = ft_gettime();
	pthread_mutex_unlock(&philo->mlast_lunch);
	pthread_mutex_lock(&philo->mtime_stamp);
	philo->time_stamp = ft_gettime();
	pthread_mutex_unlock(&philo->mtime_stamp);
	pthread_mutex_lock(&philo->mnb_lunch);
	philo->nb_lunch = 0;
	pthread_mutex_unlock(&philo->mnb_lunch);
	if (philo->id % 2)
	{
		ft_print_msg(philo, 4);
		ft_usleep(philo->time_to_eat / 3);
	}
	while (!ft_the_glorious_dead(philo))
	{
		ft_eat(philo);
		ft_print_msg(philo, 3);
		ft_usleep(philo->time_to_sleep);
		ft_print_msg(philo, 4);
	}
	return ((void *)philo);
}

int	ft_check_tepme(t_common *data, int i)
{
	pthread_mutex_lock(&data->philo[i].mnb_lunch);
	if (data->philo[i].nb_lunch > data->nb_of_tepme)
	{
		pthread_mutex_lock(data->philo->mthe_glorious_dead);
		data->the_glorious_dead = 1;
		pthread_mutex_unlock(data->philo[i].mthe_glorious_dead);
		pthread_mutex_unlock(&data->philo[i].mnb_lunch);
		return (1);
	}
	pthread_mutex_unlock(&data->philo[i].mnb_lunch);
	return (0);
}

void	ft_end_check(t_common *data)
{
	int				i;
	uint64_t		temp;

	ft_usleep(data->time_to_eat / 3);
	while (!data->the_glorious_dead)
	{
		i = 0;
		ft_usleep(5);
		while (i < data->nb_of_philos)
		{
			pthread_mutex_lock(&data->philo[i].mlast_lunch);
			if (data->philo[i].last_lunch != 0)
				temp = ft_gettime() - data->philo[i].last_lunch;
			pthread_mutex_unlock(&data->philo[i].mlast_lunch);
			if (data->nb_of_tepme)
				if (ft_check_tepme(data, i))
					break ;
			if (temp >= (uint64_t)data->time_to_die)
			{
				ft_set_death(data, i);
				break ;
			}
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
		i = 0;
		ft_end_check(data);
		while (i < data->nb_of_philos)
		{
			pthread_join(data->philo[i].thread, NULL);
			i++;
		}
		ft_destroy_mutex(data);
	}
	else
		return (1);
	return (0);
}
