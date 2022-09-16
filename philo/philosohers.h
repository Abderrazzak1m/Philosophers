/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosohers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:26:11 by amiski            #+#    #+#             */
/*   Updated: 2022/09/16 17:58:06 by amiski           ###   ########.fr       */
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
    pthread_t philo;
    int id;
    pthread_mutex_t fork;
    int nbr_eat;
    int             time;
    struct s_philo  *next;
    struct s_philo *prev;
    struct s_info *data;
}   t_philo;

typedef struct s_info
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat;
    int is_die;
    int finish_eat;
    unsigned long start_time;
    pthread_mutex_t print;
    
}   t_info;

typedef struct s_forks
{
    pthread_mutex_t *leftfork;
    pthread_mutex_t *rightfork;
}   t_forks;

int	ft_atoi(const char *str);
void append(t_philo **philo, t_philo *newphilo);
t_philo *new(t_info *data, int id);
void init(t_philo **philo, char **argv);
unsigned long current_time();
void *check_is_die(void *p);
void	tasks(t_philo *philo);


#endif