/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:08:16 by amiski            #+#    #+#             */
/*   Updated: 2022/09/17 15:57:48 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philosophers.h"

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

static void	ft_clear(t_philo **philo)
{
	t_philo	*forfree;
	t_philo	*tmp;

	tmp = *philo;
	pthread_mutex_destroy(&tmp->data->print);
	while (tmp)
	{
		pthread_mutex_destroy(&tmp->fork);
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
	t_philo	*philo;

	if (!check_args(argc, argv))
		return (0);
	if (!init(&philo, argv))
		ft_clear(&philo);
	return (0);
}
