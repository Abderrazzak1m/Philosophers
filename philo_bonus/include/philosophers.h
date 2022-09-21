/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:33:28 by amiski            #+#    #+#             */
/*   Updated: 2022/09/21 01:41:09 by amiski           ###   ########.fr       */
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
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_philo
{
	int				pid;
	int				id;
	int				nbr_eat;
	unsigned long	time;
	int				is_die;
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
	int				finish_eat;
	sem_t			*done;
	unsigned long	start_time;
	sem_t			*forks;
	sem_t			*print;
}	t_info;

int				init(t_philo **philo, char **argv);
int				ft_atoi(const char *str);
int				append(t_philo **philo, t_philo *newphilo);
t_philo			*new(t_info *data, int id);
unsigned long	current_time(void);
void			tasks(t_philo *philo);
void			ft_usleep(unsigned long time, unsigned long start);
void			print(t_philo *philo, char task);
void			*check_is_die(void *p);
#endif