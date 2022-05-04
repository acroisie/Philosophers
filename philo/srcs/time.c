/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:51:57 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/04 13:16:26 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

unsigned int	ft_gettime(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		return (1);
	return ((current_time.tv_sec) * 1000 + (current_time.tv_usec) / 1000);
}

void	ft_usleep(long int ms)
{
	unsigned int	start;

	start = ft_gettime();
	while ((ft_gettime() - start) < ms)
		usleep(20);
}
