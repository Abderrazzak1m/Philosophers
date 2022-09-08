/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosohers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:26:11 by amiski            #+#    #+#             */
/*   Updated: 2022/09/08 20:04:16 by amiski           ###   ########.fr       */
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
    int id;
    pthread_mutex_t fork;
   
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
    unsigned long start_time;
    
}   t_info;
#endif