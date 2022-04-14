/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:49:39 by acroisie          #+#    #+#             */
/*   Updated: 2022/04/14 16:23:51 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc >= 4 && argc <= 5)
	{
		return (0);
	}
	ft_putendl_fd("Wrong arguments", 2);
	return (1);
}
