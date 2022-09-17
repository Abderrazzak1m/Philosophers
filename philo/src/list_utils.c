/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:08:09 by amiski            #+#    #+#             */
/*   Updated: 2022/09/17 19:22:57 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philosophers.h"

t_philo	*new(t_info *data, int id)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->next = NULL;
	philo->prev = NULL;
	philo->data = data;
	philo->id = id;
	philo->nbr_eat = 0;
	pthread_mutex_init(&philo->fork, NULL);
	return (philo);
}

int	append(t_philo **philo, t_philo *newphilo)
{
	t_philo	*last;

	last = *philo;
	if (newphilo == NULL)
		return (0);
	if (*philo == NULL)
	{
		*philo = newphilo;
		return (1);
	}
	while (last->next != NULL)
		last = last->next;
	last->next = newphilo;
	newphilo->prev = last;
	return (1);
}
