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
    if(philo->data->is_die == 1)
        return ;
    else
        pthread_mutex_lock(&philo->data->print);
    time = current_time() - philo->data->start_time;
    if (task == 'f')
        printf("%d\t%d\thas taken a fork\n", philo->id, time);
    else if (task == 't')
        printf("%d\t%d\tis thinking\n", philo->id, time);
    else if (task == 's')
        printf("%d\t%d\tis sleeping\n", philo->id, time);
    else if (task == 'e')
        printf("%d\t%d\tis eating\n", philo->id, time);
    pthread_mutex_unlock(&philo->data->print);
    printf("for check out%dh\n", philo->id);
}
void eating(t_philo *philo)
{
    if(philo->data->is_die == 1)
        return ;
    print(philo, 'e');
    usleep(philo->data->time_to_eat * 1000);
    philo->time = current_time() + philo->data->time_to_die;
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
    print(philo, 'f');
    eating(philo);
    pthread_mutex_unlock(forks.leftfork);
    pthread_mutex_unlock(forks.rightfork);
    print(philo, 's');
    if(philo->data->is_die == 1)
        return ;
    usleep(philo->data->time_to_sleep * 1000);
    print(philo, 't');

        
}