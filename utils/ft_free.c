#include "../philo.h"


void	ft_clean(t_args *round_table, pthread_t *id)
{
	int	i;

	i = -1;
	while (++i < round_table->nbr_of_philos)
		pthread_join(id[i], NULL);
	i = -1;
	while (++i < round_table->nbr_of_philos)
		pthread_mutex_destroy(&round_table->philos[i].fork);
	pthread_mutex_destroy(&round_table->print);
	pthread_mutex_destroy(&round_table->supervisor);
	free(round_table->philos);
	free(id);
}