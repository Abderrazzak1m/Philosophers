/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:55:43 by amiski            #+#    #+#             */
/*   Updated: 2022/09/16 19:01:45 by amiski           ###   ########.fr       */
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



void *check_is_die(void *p)
{
	t_philo *tmp;
	t_philo **philo;
	int	time;
	int t;
	philo = p;
	tmp = *philo;
	while(tmp != NULL)
	{
		t = current_time() - tmp->data->start_time;
		if (t > (tmp->data->time_to_die ))
		{
			tmp->data->is_die = 1;
			usleep(100);
			pthread_mutex_lock(&tmp->data->print);
			time = current_time() - tmp->data->start_time;
			printf("%d %d is die\n",tmp->id, time);
			//exit(0);
			return (NULL);
		
		}
		if(tmp->next == NULL)
		{
			tmp = *philo;
		}
		else
			tmp = tmp->next;
	}
	return (NULL);
}

/*void ft_join(t_philo **philo)
{

}*/