/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:41:54 by acroisie          #+#    #+#             */
/*   Updated: 2022/04/20 17:29:59 by acroisie         ###   ########lyon.fr   */
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

void	ft_init_mutex(t_common *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philos)
		pthread_mutex_init(&data->philo[i++].left_fork, NULL);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	printf("taken a fork"); // To modify
	pthread_mutex_lock(philo->right_fork);
	ft_usleep(data->time_to_eat); // To copy into philo to avoid datarace
}

void	*ft_process(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo->id % 2)
		ft_eat(philo);
	return ((void *)philo);
}

int	ft_lets_philo(t_common *data, char **argv)
{
	int	i;

	i = 0;
	ft_init_mutex(data);
	ft_init_data(data, argv);
	if (data->philo)
		while (i < data->nb_of_philos)
			pthread_create(&data->philo[i++].thread, NULL, \
			ft_process, data->philo);
	else
		return (1);
	/* Mutex_join */
	return (0);
}

/* Copy data into philo & malloc data */