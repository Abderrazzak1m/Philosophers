/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:57:37 by amiski            #+#    #+#             */
/*   Updated: 2022/09/21 01:41:02 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philosophers.h"

void	eating(t_philo *philo)
{
	philo->time = current_time() + philo->data->time_to_die;
	print(philo, 'e');
	ft_usleep(philo->data->time_to_eat, current_time());
	philo->nbr_eat++;
	if (philo->nbr_eat == philo->data->must_eat)
		sem_post(philo->data->done);
}

void	print(t_philo *philo, char task)
{
	int	time;

	sem_wait(philo->data->print);
	time = current_time() - philo->data->start_time;
	if (task == 'f')
		printf("%d\t%d\thas taken a fork\n", time, philo->id);
	else if (task == 't')
		printf("%d\t%d\tis thinking\n", time, philo->id);
	else if (task == 's')
		printf("%d\t%d\tis sleeping\n", time, philo->id);
	else if (task == 'e')
		printf("%d\t%d\tis eating\n", time, philo->id);
	else if (task == 'd')
		printf("%d\t%d\tis die\n", time, philo->id);
	if (philo->is_die == 0)
		sem_post(philo->data->print);
}

void	for_eat(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print(philo, 'f');
	sem_wait(philo->data->forks);
	print(philo, 'f');
	eating(philo);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	tasks(t_philo *philo)
{
	while (1)
	{	
		for_eat(philo);
		print(philo, 's');
		ft_usleep(philo->data->time_to_sleep, current_time());
		print(philo, 't');
	}
}
