/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:36:38 by amiski            #+#    #+#             */
/*   Updated: 2022/09/21 01:41:11 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_sem(t_info *data)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("done");
	data->forks = sem_open("forks", O_CREAT, 777, data->number_of_philosophers);
	data->print = sem_open("print", O_CREAT, 777, 1);
	data->done = sem_open("done", O_CREAT, 777, 0);
}

void	routine(t_philo *philo)
{
	pthread_t	fordie;

	if (philo->id % 2 == 0)
		usleep(100);
	philo->time = philo->data->start_time + philo->data->time_to_die;
	pthread_create(&fordie, NULL, &check_is_die, philo);
	tasks(philo);
	pthread_join(fordie, NULL);
}

void	start(t_philo **philo)
{
	t_philo	*tmp;
	int		pid;

	(*philo)->data->start_time = current_time();
	tmp = *philo;
	while (tmp)
	{
		pid = fork();
		if (pid == 0)
		{
			tmp->time = tmp->data->start_time + tmp->data->time_to_die;
			routine(tmp);
		}
		tmp->pid = pid;
		tmp = tmp->next;
	}
}

static int	init_philo(t_info *data, t_philo **philo)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		if (append(philo, new(data, i + 1)) == 0)
			return (0);
	}
	(*philo)->data->start_time = current_time();
	start(philo);
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
	init_sem(data);
	return (init_philo(data, philo));
}
