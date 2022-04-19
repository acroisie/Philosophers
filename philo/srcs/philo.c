/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:41:54 by acroisie          #+#    #+#             */
/*   Updated: 2022/04/19 13:43:56 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_data(t_common *data, char **argv)
{
	int	i;

	i = 0;
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->number_of_tepme = ft_atoi(argv[5]);
	else
		data->number_of_tepme = 0;
	data->philo = malloc(data->number_of_philosophers * sizeof(t_philo *));
	if (data->philo)
		while (i++ <= data->number_of_philosophers)
			data->philo[i].right_fork = &data->philo[i + 1].left_fork;
	else
		free(data->philo);
}

void	*ft_process(void *arg)
{
	t_common	*data;

	data = (t_common *) arg;
	ft_putendl_fd("lets_philo", 1);
	return ((void *)data);
}

int	lets_philo(t_common *data, char **argv)
{
	int	i;

	i = 0;
	init_data(data, argv);
	if (data->philo)
		while (i < data->number_of_philosophers)
			pthread_create(&data->philo[i++].thread, NULL, ft_process, data);
	else
		return (1);
	/* Mutex_join */
	return (0);
}
