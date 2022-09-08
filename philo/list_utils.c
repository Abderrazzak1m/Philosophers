#include "philosohers.h"
t_philo *new(t_info *data, int id)
{
    t_philo *philo;
    philo = (t_philo *)malloc(sizeof(t_philo));
    if(philo != NULL)
    {
        philo->next = NULL;
        philo->prev = NULL;
        philo->data = data;
        philo->id = id;
        philo->nbr_eat = 0;
        pthread_mutex_init(&philo->fork, NULL);
    }
    return(philo);
}
void append(t_philo **philo, t_philo *newphilo)
{
    t_philo *last;

    last = *philo;
    if(*philo == NULL)
    {
        *philo = newphilo;
        return;
    }
    while(last->next !=NULL)
        last = last->next;
    last->next = newphilo;
    newphilo->prev = last;
    return ;
}
