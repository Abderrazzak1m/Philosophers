/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:52:43 by amiski            #+#    #+#             */
/*   Updated: 2022/09/17 19:20:18 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		philo;
	int				id;
	pthread_mutex_t	fork;
	int				nbr_eat;
	unsigned long	time;
	struct s_philo	*next;
	struct s_philo	*prev;
	struct s_info	*data;
}	t_philo;

typedef struct s_info
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				is_die;
	int				finish_eat;
	unsigned long	start_time;
	pthread_mutex_t	print;

}	t_info;

typedef struct s_forks
{
	pthread_mutex_t	*leftfork;
	pthread_mutex_t	*rightfork;
}	t_forks;

int				ft_atoi(const char *str);
int				append(t_philo **philo, t_philo *newphilo);
t_philo			*new(t_info *data, int id);
int				init(t_philo **philo, char **argv);
unsigned long	current_time(void);
void			*check_is_die(void *p);
void			tasks(t_philo *philo);
void			ft_usleep(unsigned long time, unsigned long start);
void			print(t_philo *philo, char task);

#endif
