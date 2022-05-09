/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:56:43 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/09 10:06:22 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] - s2[i] != 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_atoi(char const *str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 3 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = sign * -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - 48);
		if ((result > 2147483647 && sign >= 0)
			|| (result > 2147483648 && sign < 0))
		{
			if (sign >= 0)
				return (-1);
			else
				return (0);
		}
	}
	return (result * sign);
}

void	ft_print_msg(t_philo *philo, int msg_id)
{
	uint64_t	tmp;

	if (msg_id == 5)
	{
		pthread_mutex_lock(&philo->mtime_stamp);
		tmp = ft_gettime() - (uint64_t)philo->time_stamp;
		pthread_mutex_unlock(&philo->mtime_stamp);
		printf("%llu %d died\n", tmp, philo->id);
	}
	else if (!ft_the_glorious_dead(philo))
	{
		pthread_mutex_lock(&philo->mtime_stamp);
		tmp = ft_gettime() - (uint64_t)philo->time_stamp;
		pthread_mutex_unlock(&philo->mtime_stamp);
		pthread_mutex_lock(philo->print_msg);
		if (msg_id == 1)
			printf("%llu %d has taken a fork\n", tmp, philo->id);
		else if (msg_id == 2)
			printf("%llu %d is eating\n", tmp, philo->id);
		else if (msg_id == 3)
			printf("%llu %d is sleeping\n", tmp, philo->id);
		else if (msg_id == 4)
			printf("%llu %d is thinking\n", tmp, philo->id);
		pthread_mutex_unlock(philo->print_msg);
	}
}

int	ft_check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (ft_strncmp(argv[i], "0", ft_strlen(argv[i])))
			if (ft_strncmp(argv[i], "-1", ft_strlen(argv[i])))
				if (ft_atoi(argv[i]) == 0 || ft_atoi(argv[i]) == (-1))
					return (1);
		if (argv[i][j] == '-' || (argv[i][j] == '0' && i != 5))
			return (1);
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
