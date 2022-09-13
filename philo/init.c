#include"philosohers.h"
void *routine(void *p)
{
    t_philo **philo;
    t_philo *tmp;
    philo = (t_philo **)p;
    tmp = *philo;
    while(tmp != NULL)
    {
        take_a_fork()
        
    }


}
void init_philo(t_info *data, t_philo **philo)
{
    int i;
    t_philo *tmp;
    i = -1;
    while(++i < data->number_of_philosophers)
        append(philo, new(data, i));
    tmp = *philo;
    while(tmp != NULL)
    {
        ptread_create(&tmp->philo, NULL, &routine, philo);
        pthread_join(&tmp->philo, NULL);
    }
}
void init(t_philo **philo, char **argv)
{
    t_info *data;

    data = (t_info*)malloc(sizeof(t_info));
    data->number_of_philosophers = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    if(argv[5])
        data->must_eat = ft_atoi(argv[5]);
    else
        data->must_eat = -1;
    data->start_time = current_time();
    pthread_mutex_init(&data->print, NULL);
    init_philo(data, philo);
}