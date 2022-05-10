/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:59:47 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/10 15:26:33 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_print_death(t_philo *philo)
{
	uint64_t	tmp;

	pthread_mutex_lock(philo->print_msg);
	pthread_mutex_lock(&philo->mtime_stamp);
	tmp = ft_gettime() - (uint64_t)philo->time_stamp;
	pthread_mutex_unlock(&philo->mtime_stamp);
	printf("%llu %d died\n", tmp, philo->id);
	pthread_mutex_unlock(philo->print_msg);
}

void	ft_print_msg(t_philo *philo, int msg_id)
{
	uint64_t	tmp;

	if (msg_id == 5)
		ft_print_death(philo);
	if (!ft_the_glorious_dead(philo))
	{
		pthread_mutex_lock(philo->print_msg);
		if (!ft_the_glorious_dead(philo))
		{
			pthread_mutex_lock(&philo->mtime_stamp);
			tmp = ft_gettime() - (uint64_t)philo->time_stamp;
			pthread_mutex_unlock(&philo->mtime_stamp);
			if (msg_id == 1)
				printf("%llu %d has taken a fork\n", tmp, philo->id);
			if (msg_id == 2)
				printf("%llu %d is eating\n", tmp, philo->id);
			if (msg_id == 3)
				printf("%llu %d is sleeping\n", tmp, philo->id);
			if (msg_id == 4)
				printf("%llu %d is thinking\n", tmp, philo->id);
		}
		pthread_mutex_unlock(philo->print_msg);
	}
}

void	ft_set_death(t_common *data, int i)
{
	pthread_mutex_lock(data->philo->mthe_glorious_dead);
	data->the_glorious_dead = 1;
	pthread_mutex_unlock(data->philo[i].mthe_glorious_dead);
	ft_print_msg(&data->philo[i], 5);
}
