#include "../philo.h"


static char	*messages(int message)
{
	if (message == TAKE_FORKS)
		return ("has taken a fork");
	if (message == EATING)
		return ("is eating");
	if (message == SLEEPING)
		return ("is sleeping");
	if (message == THINKING)
		return ("is thinking");
	if (message == DIED)
		return ("died");
	return ("Error: not valid msg id");
}



void	print_messages(t_philo *philo, int message)
{
	size_t	time;

	time = current_time() - philo->table->start_time;
	pthread_mutex_lock(&philo->table->print);
	if (!philo->table->dead && !philo->table->is_full)
	{
		printf("%ld ", time);
		printf(" %d ", philo->id);
		printf("%s", messages(message));
		printf("\n");
	}
	pthread_mutex_unlock(&philo->table->print);
}





// time in ms
size_t	current_time(void)
{
	struct timeval	tvalue;

	gettimeofday(&tvalue, NULL);
	return ((tvalue.tv_sec * 1000) + (tvalue.tv_usec / 1000));
}



// pauses exec for  time in ms
void	ft_delay(t_args *round_table, size_t time)
{
	size_t	t;

	t = current_time();
	while (!(round_table->dead))
	{
		if (current_time() - t >= time)
			break ;
		usleep(100);
	}
}
