
NAME    =   philo
CC      =   @clang
CFLAGS  =   -g -Wall -Wextra -Werror
RM = @rm -f
VALGRIND = valgrind --leak-check=full
SRC =  ft_philo.c\
		ft_args.c\
		main.c\
		utils/ft_checks.c\
		utils/ft_helpers.c\
		utils/ft_errors.c\
		utils/ft_utils.c\
		utils/ft_free.c


OBJ = $(SRC:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
valgrind: all
	$(VALGRIND) ./$(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY: re fclean clean all re
