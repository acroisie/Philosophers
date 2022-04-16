/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:49:39 by acroisie          #+#    #+#             */
/*   Updated: 2022/04/15 17:48:29 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	if (argc >= 5 && argc <= 6)
	{
		if (!check_args(argv))
		{
			lets_philo(argv);
			return (0);
		}
	}
	ft_putendl_fd("Wrong arguments", 2);
	return (1);
}
