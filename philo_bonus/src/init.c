#include "../include/philosophers.h"
void init_sem(t_info *data)
{
    sem_unlink("forks");
    sem_unlink("print");
    data->forks = sem_open("forks", O_CREAT, 777, data->number_of_philosophers);
    data->print = sem_open("print", O_CREAT, 777,1);
}
static int	init_philo(t_info *data, t_philo **philo)
{
	int			i;


	i = -1;
	while (++i < data->number_of_philosophers)
	{
		if (append(philo, new(data, i)) == 0)
			return (0);
	}
	//(*philo)->data->start_time = current_time();
	return (0);
}

int	init(t_philo **philo, char **argv)
{
	t_info	*data;

	data = (t_info *)malloc(sizeof(t_info));
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	data->finish_eat = 0;
    init_sem(data);
	return (init_philo(data, philo));
}