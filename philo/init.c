#include"philosohers.h"
void init_philo(t_info *data, t_philo **philo)
{
    int i;
    i = -1;
    while(++i < data->number_of_philosophers)
        append(philo, new(data, i));
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
    init_philo(data, philo);
}