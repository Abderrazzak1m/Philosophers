#include "philosohers.h"
static t_forks getforks(t_philo *philo)
{
    t_philo *first;
    t_forks forks;
    first = philo;
    while(first->prev != NULL)
        first = first->prev;
    forks.leftfork = &philo->fork;
    if(philo->next == NULL)
        forks.rightfork = &first->fork;
    else
        forks.rightfork = &philo->next->fork;

    return(forks);
}
void print(t_philo *philo, char task)
{
    int time;
    pthread_mutex_lock(&philo->data->print);
    time = current_time() - philo->data->start_time;
    if (task == 'f')
        printf("%d\t%d\thas taken a fork", philo->id + 1, time);
    else if (task == 't')
        printf("%d\t%d\tis thinking", philo->id + 1, time);
    else if (task == 's')
        printf("%d\t%d\tis sleeping", philo->id + 1, time);
    else if (task == 'e')
        printf("%d\t%d\tis eating", philo->id + 1, time);
    pthread_mutex_unlock(&philo->data->print);
}
void eating(t_philo *philo)
{
    print(philo, 'e');
    usleep(philo->data->time_to_eat * 1000);
    philo->nbr_eat++;
    if(philo->nbr_eat == philo->data->must_eat)
        philo->data->finish_eat++;
}
void	tasks(t_philo *philo)
{
    t_forks forks;
  
    forks = getforks(philo);
	pthread_mutex_lock(forks.leftfork);
	print(philo, 'f');
    pthread_mutex_lock(forks.rightfork);
    eating(philo);
    pthread_mutex_unlock(forks.leftfork);
    pthread_mutex_unlock(forks.rightfork);
    print(philo, 's');
    usleep(philo->data->time_to_sleep * 1000);
    print(philo, 't');

        
}