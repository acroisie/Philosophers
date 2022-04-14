/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:56:43 by acroisie          #+#    #+#             */
/*   Updated: 2022/04/14 16:49:50 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static	int	num_len(long int num)
{
	int	count;

	count = 0;
	if (num == 0)
		count++;
	if (num < 0)
	{
		count++;
		num = num * (-1);
	}
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	int			sign;
	long int	buff;

	buff = n;
	len = num_len(buff);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	sign = 0;
	if (buff < 0)
	{
		buff = buff * -1;
		sign = -1;
	}
	while ((--len) >= 0)
	{
		str[len] = (buff % 10) + 48;
		buff = buff / 10;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;
	int	len;

	if (!s)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
