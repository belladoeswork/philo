#include "philo.h"


int	main(int argc, char *argv[])
{
	int			i;
	t_args		round_table;
	pthread_t	*id;

	if ((argc < 5 || argc > 6) || ft_init_args(argc, argv, &round_table))
		return (ft_error());
	id = (pthread_t *)malloc(round_table.nbr_of_philos * sizeof(pthread_t));
	round_table.start_time = current_time();
	i = -1;
	while (++i < round_table.nbr_of_philos)
	{
		if (pthread_create(&id[i], NULL, &life_of_philo, &round_table.philos[i]))
		{
			write(2, "Error! cannot create thread\n", 28);
			free(round_table.philos);
			free(id);
			return (1);
		}
		pthread_mutex_lock(&round_table.supervisor);
		round_table.philos[i].last_meal = round_table.start_time;
		pthread_mutex_unlock(&round_table.supervisor);
	}
	is_philo_alive(&round_table);
	ft_clean(&round_table, id);
	return (0);
}
