/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:08:43 by amiski            #+#    #+#             */
/*   Updated: 2022/09/17 19:21:21 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philosophers.h"

void	*routine(void *p)
{
	t_philo	*tmp;

	tmp = p;
	tmp->time = tmp->data->start_time + tmp->data->time_to_die;
	while (tmp->data->is_die == 0)
		tasks(tmp);
	return (NULL);
}

static int	init_philo(t_info *data, t_philo **philo)
{
	int			i;
	pthread_t	fordie;
	t_philo		*tmp;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		if (append(philo, new(data, i)) == 0)
			return (0);
	}
	(*philo)->data->start_time = current_time();
	tmp = *philo;
	while (tmp != NULL)
	{
		pthread_create(&tmp->philo, NULL, &routine, tmp);
		pthread_detach(tmp->philo);
		tmp = tmp->next;
	}
	pthread_create(&fordie, NULL, &check_is_die, philo);
	pthread_join(fordie, NULL);
	return (0);
}

int	init(t_philo **philo, char **argv)
{
	t_info	*data;

	data = (t_info *)malloc(sizeof(t_info));
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	data->finish_eat = 0;
	data->is_die = 0;
	pthread_mutex_init(&data->print, NULL);
	return (init_philo(data, philo));
}
