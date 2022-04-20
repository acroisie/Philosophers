/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:41:54 by acroisie          #+#    #+#             */
/*   Updated: 2022/04/20 12:49:40 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_init_data(t_common *data, char **argv)
{
	int	i;

	i = 0;
	data->nb_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->nb_of_tepme = 0;
	if (argv[5])
		data->nb_of_tepme = ft_atoi(argv[5]);
	data->philo = malloc(data->nb_of_philos * sizeof(t_philo *));
	if (data->philo)
	{
		while (i < data->nb_of_philos)
		{
			data->philo[i].id = i + 1;
			if (i + 1 < data->nb_of_philos)
				data->philo[i].right_fork = &data->philo[i + 1].left_fork;
			else
				data->philo[i].right_fork = &data->philo[0].left_fork;
			data->philo[i++].common = &data;
		}
	}
	else
		free(data->philo);
}

void	*ft_process(void *arg)
{
	t_common	*data;

	data = (t_common *) arg;
	if (data->philo->id % 2 == 0)
		ft_eat();
	while (ft_someone_is_dead())
	return ((void *)data);
}

int	ft_lets_philo(t_common *data, char **argv)
{
	int	i;

	i = 0;
	ft_init_data(data, argv);
	if (data->philo)
		while (i < data->nb_of_philos)
			pthread_create(&data->philo[i++].thread, NULL, ft_process, data);
	else
		return (1);
	/* Mutex_join */
	return (0);
}
