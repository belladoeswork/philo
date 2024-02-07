
#ifndef PHILO_H
# define PHILO_H
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>


enum e_msg {
	TAKE_FORKS = 0,
	EATING,
	SLEEPING,
	THINKING,
	DIED
};

typedef struct s_philo
{
	int id;				
	int has_eaten;			
	size_t last_meal;	 
	pthread_mutex_t fork;
	struct s_philo *next;
	struct s_philo *prev; 
		struct s_args	*table;

}	t_philo;

typedef struct s_args
{
	int time_hungry; 
	int eating_time; 
	int sleeping_time;
	int meals;
	int nbr_of_philos;
	int is_full;	 
	int dead;
	size_t start_time; 
	t_philo			*philos;
	pthread_mutex_t print;		
	pthread_mutex_t supervisor; 
}	t_args;



//	utils
void check_status(t_args *round_table);
void is_philo_alive(t_args *round_table);
 int ft_error(void);
void ft_clean(t_args *round_table, pthread_t *id);
void print_messages(t_philo *philo, int message);
size_t current_time(void);
void ft_delay(t_args *round_table, size_t time);
void ft_putstr(char *str);
int ft_atoi(const char *nptr);
long ft_atoi_long(const char *str);
int ft_isdigit(int c);
size_t ft_strlen(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);
size_t current_time(void);

// src
int ft_init_args(int argc, char *argv[], t_args *arguments);
void *life_of_philo(void *arg);


#endif

