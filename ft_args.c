# include "philo.h"



static int	arguments_are_num(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		if (argv[i][0] == '-')
			return (1);
		else if (argv[i][0] == '+')
			j++;
		if (!ft_isdigit(argv[i][j + 1]))
			return (1);
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
		}
	}
	return (0);
}


static int	is_within_range(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (*str == '+' && str++)
		len--;
	while (*str == '0' && *str && len--)
		str++;
	if (len > 10)
		return (1);
	else if (len < 10)
		return (0);
	if (ft_strncmp(str, "2147483648", 10) >= 0)
		return (1);
	return (0);
}


static int	validate_args(int argc, char *argv[])
{
	int	i;

	if (arguments_are_num(argc, argv))
		return (1);
	i = 0;
	while (++i < argc)
	{
		if (is_within_range(argv[i]))
			return (1);
	}
	return (0);
}




static void	ft_init_philo(t_args *round_table)
{
	int	i;

	round_table->dead = 0;
	round_table->is_full = 0;
	round_table->philos = (t_philo *)malloc(round_table->nbr_of_philos * sizeof(t_philo));
	i = -1;
	while (++i < round_table->nbr_of_philos) 
	{
		round_table->philos[i].id = i + 1;
		round_table->philos[i].table = round_table;
		round_table->philos[i].has_eaten = 0;
		if (i + 1 == round_table->nbr_of_philos)
			round_table->philos[i].next = &round_table->philos[0];
		else
			round_table->philos[i].next = &round_table->philos[i + 1];
		if (i == 0)
			round_table->philos[i].prev = &round_table->philos[round_table->nbr_of_philos - 1];
		else
			round_table->philos[i].prev = &round_table->philos[i - 1];
		pthread_mutex_init(&round_table->philos[i].fork, NULL);
	}
	pthread_mutex_init(&round_table->print, NULL);
	pthread_mutex_init(&round_table->supervisor, NULL);
}



int	ft_init_args(int argc, char *argv[], t_args *arguments)
{
	if (validate_args(argc, argv))
		return (1);
	arguments->nbr_of_philos = ft_atoi(argv[1]);
	arguments->time_hungry = ft_atoi(argv[2]);
	arguments->eating_time = ft_atoi(argv[3]);
	arguments->sleeping_time = ft_atoi(argv[4]);
	arguments->meals = -1;
	if (argc == 6)
		arguments->meals = ft_atoi(argv[5]);
	ft_init_philo(arguments);
	return (0);
}
