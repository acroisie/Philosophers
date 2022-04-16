/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:41:54 by acroisie          #+#    #+#             */
/*   Updated: 2022/04/16 11:24:16 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_common	init_data(char **argv)
{
	t_common	temp;

	temp.number_of_philosophers = ft_atoi(argv[1]);
	temp.time_to_die = ft_atoi(argv[2]);
	temp.time_to_eat = ft_atoi(argv[3]);
	temp.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		temp.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		temp.number_of_times_each_philosopher_must_eat = 0;
	return (temp);
}

void	lets_philo(char **argv)
{
	t_common	data;

	data = init_data(argv);
	ft_putendl_fd("lets_philo", 1);
	printf("%i\n", data.number_of_philosophers);
	printf("%i\n", data.time_to_die);
	printf("%i\n", data.time_to_eat);
	printf("%i\n", data.time_to_sleep);
	printf("%i\n", data.number_of_times_each_philosopher_must_eat);
}
