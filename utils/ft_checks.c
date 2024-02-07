#include "../philo.h"


void	check_status(t_args *round_table)
{
	int	i;

	while (!round_table->is_full)
	{
		i = -1;
		while (!round_table->dead && ++i < round_table->nbr_of_philos)
		{
			pthread_mutex_lock(&round_table->supervisor);
			if (current_time() - round_table->philos[i].last_meal > (size_t)round_table->time_hungry)
			{
				print_messages(&round_table->philos[i], DIED);
				round_table->dead = 1;
			}
			pthread_mutex_unlock(&round_table->supervisor);
			usleep(100);
		}
		if (round_table->dead)
			break ;
		i = 0;
		while (round_table->meals != -1 && i < round_table->nbr_of_philos
			&& round_table->philos[i].has_eaten >= round_table->meals)
			i++;
		if (i == round_table->nbr_of_philos)
			round_table->is_full = 1;
	}
}



void	is_philo_alive(t_args *round_table)
{
	int	i;

	while (!round_table->is_full)
	{
		i = -1;
		while (!round_table->dead && ++i < round_table->nbr_of_philos)
		{
			pthread_mutex_lock(&round_table->supervisor);
			if (current_time() - round_table->philos[i].last_meal > (size_t)round_table->time_hungry)
			{
				print_messages(&round_table->philos[i], DIED);
				round_table->dead = 1;
			}
			pthread_mutex_unlock(&round_table->supervisor);
			usleep(100);
		}
		if (round_table->dead)
			break ;
		i = 0;
		while (round_table->meals != -1 && i < round_table->nbr_of_philos
			&& round_table->philos[i].has_eaten >= round_table->meals)
			i++;
		if (i == round_table->nbr_of_philos)
			round_table->is_full = 1;
	}
}

