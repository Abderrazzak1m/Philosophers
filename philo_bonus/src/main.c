/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:47:40 by amiski            #+#    #+#             */
/*   Updated: 2022/09/20 22:14:11 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 6 && argc != 5)
	{
		printf("bad input");
		return (0);
	}
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
			{
				printf("bad input");
				return (0);
			}
		}
	}
	return (1);
}

void	ft_clear(t_philo **philo)
{
	t_philo	*tmp;
	t_philo	*forfree;

	tmp = *philo;
	while (tmp)
	{
		kill(tmp->pid, SIGINT);
		tmp = tmp->next;
	}
	while (*philo)
	{
		forfree = *philo;
		*philo = (*philo)->next;
		free(forfree);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_philo	*philo;

	if (!check_args(argc, argv))
		return (0);
	init(&philo, argv);
	i = -1;
	while (++i < philo->data->number_of_philosophers)
		sem_wait(philo->data->done);
	ft_clear(&philo);
	return (0);
}
