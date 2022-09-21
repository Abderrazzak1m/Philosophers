/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:07:47 by amiski            #+#    #+#             */
/*   Updated: 2022/09/20 21:45:08 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	eating(t_philo *philo)
{
	philo->time = current_time() + philo->data->time_to_die;
	if (philo->data->is_die == 1)
		return ;
	print(philo, 'e');
	ft_usleep(philo->data->time_to_eat, current_time());
	philo->nbr_eat++;
	if (philo->nbr_eat == philo->data->must_eat)
		philo->data->finish_eat++;
}

static t_forks	getforks(t_philo *philo)
{
	t_philo	*first;
	t_forks	forks;

	first = philo;
	while (first->prev != NULL)
		first = first->prev;
	forks.leftfork = &philo->fork;
	if (philo->next == NULL)
		forks.rightfork = &first->fork;
	else
		forks.rightfork = &philo->next->fork;
	return (forks);
}

void	print(t_philo *philo, char task)
{
	int	time;

	if (philo->data->is_die == 1 || philo->data->finish_eat == \
		philo->data->number_of_philosophers)
		return ;
	else
		pthread_mutex_lock(&philo->data->print);
	time = current_time() - philo->data->start_time;
	if (task == 'f')
		printf("%d\t%d\thas taken a fork\n", time, philo->id);
	else if (task == 't')
		printf("%d\t%d\tis thinking\n", time, philo->id);
	else if (task == 's')
		printf("%d\t%d\tis sleeping\n", time, philo->id);
	else if (task == 'e')
		printf("%d\t%d\tis eating\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->print);
}

void	for_eat(t_philo *philo)
{
	t_forks	forks;

	forks = getforks(philo);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(forks.leftfork);
		print(philo, 'f');
		pthread_mutex_lock(forks.rightfork);
		print(philo, 'f');
		eating(philo);
		pthread_mutex_unlock(forks.leftfork);
		pthread_mutex_unlock(forks.rightfork);
	}
	else
	{
		pthread_mutex_lock(forks.rightfork);
		print(philo, 'f');
		pthread_mutex_lock(forks.leftfork);
		print(philo, 'f');
		eating(philo);
		pthread_mutex_unlock(forks.rightfork);
		pthread_mutex_unlock(forks.leftfork);
	}
}

void	tasks(t_philo *philo)
{
	for_eat(philo);
	print(philo, 's');
	if (philo->data->is_die == 1)
		return ;
	ft_usleep(philo->data->time_to_sleep, current_time());
	if (philo->data->is_die == 1)
		return ;
	print(philo, 't');
}
