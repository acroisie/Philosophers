/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:49:39 by acroisie          #+#    #+#             */
/*   Updated: 2022/04/15 08:40:04 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	args_isnt_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(char **argv)
{
	if (args_isnt_digit(argv))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc >= 4 && argc <= 5)
	{
		if (!check_args(argv))
		{
			ft_putendl_fd("OK", 1); // To delete
			return (0);
		}
	}
	ft_putendl_fd("Wrong arguments", 2);
	return (1);
}
