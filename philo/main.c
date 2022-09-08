#include "philosohers.h"
int check_args(int argc, char **argv)
{
    int i;
    int j;
    if(argc != 6 && argc != 5)
    {
        printf("bad input");
        return (0);
    }
    i = 0;
    while(argv[++i])
    {
        j = -1;
        while (argv[i][++j])
        {
            if(argv[i][j] > '9' || argv[i][j] < '1')
            {
                printf("bad input");
                return(0);
            }
        }
        
    }
    return(1);
}
int main(int argc, char **argv)
{
    t_philo *philo;
    if(!check_args(argc, argv))
        return(0);
    
    
}