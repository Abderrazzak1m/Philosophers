/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:56:36 by amiski            #+#    #+#             */
/*   Updated: 2022/09/21 01:41:01 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_atoi(const char *str)
{
	int	rus;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	rus = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rus = (rus * 10) + ((int)str[i] - '0');
		i++;
	}
	return (sign * rus);
}

unsigned long	current_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	ft_usleep(unsigned long time, unsigned long start)
{
	usleep(time * 1000 * 0.90);
	while (current_time() - start < time)
		usleep(50);
}

static void	*checker(t_philo *philo)
{
	int	time;
	int	i;

	i = -1;
	philo->is_die = 1;
	time = current_time() - philo->data->start_time;
	print(philo, 'd');
	while (++i < philo->data->number_of_philosophers)
		sem_post(philo->data->done);
	return (NULL);
}

void	*check_is_die(void *p)
{
	t_philo	*tmp;
	t_philo	*philo;

	philo = p;
	tmp = philo;
	while (tmp->is_die == 0)
	{
		if (current_time() >= tmp->time)
			return (checker(tmp));
		usleep(100);
	}
	return (NULL);
}
