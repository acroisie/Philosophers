/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:07:22 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/10 13:50:06 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_copy_time(t_common *data, t_philo *philo)
{
	philo->nb_of_philos = data->nb_of_philos;
	philo->time_to_die = data->time_to_die;
	philo->time_to_eat = data->time_to_eat;
	philo->time_to_sleep = data->time_to_sleep;
	philo->nb_of_tepme = data->nb_of_tepme;
}

void	ft_init_mutex(t_common *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->print_msg, NULL);
	data->the_glorious_dead = 0;
	pthread_mutex_init(&data->mthe_glorious_dead, NULL);
	while (i < data->nb_of_philos)
	{
		data->philo[i].id = i + 1;
		pthread_mutex_init(&data->philo[i].left_fork, NULL);
		pthread_mutex_init(&data->philo[i].mtime_stamp, NULL);
		pthread_mutex_init(&data->philo[i].mlast_lunch, NULL);
		pthread_mutex_init(&data->philo[i].mnb_lunch, NULL);
		data->philo[i].print_msg = &data->print_msg;
		data->philo[i].mthe_glorious_dead = &data->mthe_glorious_dead;
		data->philo[i].the_glorious_dead = &data->the_glorious_dead;
		data->philo[i].lfork_st = 1;
		i++;
	}
}

void	ft_destroy_mutex(t_common *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->print_msg);
	pthread_mutex_destroy(&data->mthe_glorious_dead);
	while (i < data->nb_of_philos)
	{
		pthread_mutex_destroy(&data->philo[i].left_fork);
		pthread_mutex_destroy(&data->philo[i].mtime_stamp);
		pthread_mutex_destroy(&data->philo[i].mlast_lunch);
		pthread_mutex_destroy(&data->philo[i].mnb_lunch);
		i++;
	}
}

void	ft_fill_data(t_common *data, char **argv)
{
	data->nb_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->nb_of_tepme = 0;
	if (argv[5])
		data->nb_of_tepme = ft_atoi(argv[5]);
}

void	ft_init_data(t_common *data, char **argv)
{
	int	i;

	i = 0;
	ft_fill_data(data, argv);
	data->philo = malloc(data->nb_of_philos * sizeof(t_philo));
	if (data->philo)
	{
		while (i < data->nb_of_philos)
		{
			if (i + 1 < data->nb_of_philos)
			{
				data->philo[i].right_fork = &data->philo[i + 1].left_fork;
				data->philo[i].rfork_st = &data->philo[i + 1].lfork_st;
			}
			else if (data->nb_of_philos > 1)
			{
				data->philo[i].right_fork = &data->philo[0].left_fork;
				data->philo[i].rfork_st = &data->philo[0].lfork_st;
			}
			ft_copy_time(data, &data->philo[i++]);
		}
		ft_init_mutex(data);
	}
	else
		free(data->philo);
}
