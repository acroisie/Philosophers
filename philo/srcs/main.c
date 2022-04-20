/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:49:39 by acroisie          #+#    #+#             */
/*   Updated: 2022/04/20 08:37:58 by acroisie         ###   ########lyon.fr   */
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
			ft_lets_philo(&data, argv);
			return (0);
		}
	}
	ft_putendl_fd("Wrong arguments", 2);
	return (1);
}
