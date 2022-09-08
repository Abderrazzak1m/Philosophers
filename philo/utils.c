/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:55:43 by amiski            #+#    #+#             */
/*   Updated: 2022/09/08 22:43:34 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosohers.h"

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

unsigned long current_time()
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return(t.tv_sec*1000 + t.tv_usec/ 1000);
}

void print_action(t_philo *philo, char *msg)
{
	int time;
	pthread_mutex_lock(&philo->data->print);
	time = current_time() - philo->data->start_time;
	prinft("%d\t%d\t%s", time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print);
	
	
	
}