#include "../philo.h"


 int	ft_error(void)

{
	write(2, "Error! invalid arguments\n", 26);
	return (1);
}