
#include "philo.h"


static void	ft_is_eating(t_philo *philo)
{
	t_args	*round_table;

	round_table = philo->table;
	pthread_mutex_lock(&philo->fork);
	print_messages(philo, TAKE_FORKS);
	if (philo->table->nbr_of_philos == 1)
	{
		ft_delay(round_table, round_table->time_hungry);
		print_messages(philo, DIED);
		pthread_mutex_unlock(&philo->fork);
		round_table->dead = 1;
		return ;
	}
	pthread_mutex_lock(&philo->next->fork);
	print_messages(philo, TAKE_FORKS);
	pthread_mutex_lock(&round_table->supervisor);
	philo->has_eaten++;
	print_messages(philo, EATING);
	philo->last_meal = current_time();
	pthread_mutex_unlock(&round_table->supervisor);
	ft_delay(round_table, round_table->eating_time);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}


void	*life_of_philo(void *arg)
{
	t_philo	*philo;
	t_args	*round_table;

	philo = (t_philo *)arg;
	round_table = philo->table;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!round_table->dead && !round_table->is_full)
	{
		ft_is_eating(philo);
		print_messages(philo, SLEEPING);
		ft_delay(round_table, round_table->sleeping_time);
		print_messages(philo, THINKING);
	}
	return (NULL);
}

