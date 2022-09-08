/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosohers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:26:11 by amiski            #+#    #+#             */
/*   Updated: 2022/09/08 21:49:56 by amiski           ###   ########.fr       */
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
    struct s_philo *next;
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
    int finish_eat;
    unsigned long start_time;
    
}   t_info;

int	ft_atoi(const char *str);
void append(t_philo **philo, t_philo *newphilo);
t_philo *new(t_info *data, int id);
void init(t_philo **philo, char **argv);

#endif