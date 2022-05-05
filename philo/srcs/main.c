/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:49:39 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/05 08:10:01 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_common	data;

	if (argc >= 5 && argc <= 6)
	{
		if (!ft_check_args(argv))
		{
			if (ft_lets_philo(&data, argv))
			{
				printf("Malloc error\n");
				return (1);
			}
			free(data.philo);
			return (0);
		}
	}
	printf("Wrong arguments\n");
	return (1);
}
