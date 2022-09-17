/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:08:32 by amiski            #+#    #+#             */
/*   Updated: 2022/09/17 19:09:55 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philosophers.h"

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
	int		time;

	if (philo->data->finish_eat == philo->data->number_of_philosophers)
	{
		philo->data->is_die = 1;
		return (NULL);
	}
	else if (current_time() > philo->time)
	{
		philo->data->is_die = 1;
		time = current_time() - philo->data->start_time;
		printf("%d %d is die\n", time, philo->id);
		return (NULL);
	}
	return (NULL);
}

void	*check_is_die(void *p)
{
	t_philo	*tmp;
	t_philo	**philo;

	philo = p;
	tmp = *philo;
	while (tmp != NULL)
	{
		if (current_time() > tmp->time || \
			tmp->data->finish_eat == tmp->data->number_of_philosophers)
			return (checker);
		if (tmp->next == NULL)
			tmp = *philo;
		else
			tmp = tmp->next;
		usleep(100);
	}
	return (NULL);
}
