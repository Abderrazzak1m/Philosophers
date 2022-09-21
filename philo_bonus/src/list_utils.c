/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:36:17 by amiski            #+#    #+#             */
/*   Updated: 2022/09/20 22:36:21 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

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
	philo->is_die = 0;
	philo->nbr_eat = 0;
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
