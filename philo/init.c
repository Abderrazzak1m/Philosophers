#include"philosohers.h"
void *routine(void *p)
{
    t_philo *tmp;
    
    tmp = p;
    tmp->time = current_time() + tmp->data->time_to_die;
    if((tmp->id) % 2 == 0)
        usleep(100);
    while(tmp->data->is_die == 0)
    {
        tasks(tmp);
    }
    return (NULL);

}
void init_philo(t_info *data, t_philo **philo)
{
    int i;
    pthread_t fordie;
    t_philo *tmp;
    i = -1;
    while(++i < data->number_of_philosophers)
        append(philo, new(data, i));
    tmp = *philo;
    pthread_create(&fordie, NULL, &check_is_die, philo);
    while(tmp != NULL)
    {
        pthread_create(&tmp->philo, NULL, &routine, tmp);
       // pthread_join(tmp->philo, NULL);
        tmp = tmp->next;
    }
    pthread_join(fordie, NULL);
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
    data->is_die = 0;
    data->start_time = current_time();
    pthread_mutex_init(&data->print, NULL);
    init_philo(data, philo);
}