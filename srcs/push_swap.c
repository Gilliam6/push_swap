#include "../includes/push_swap.h"

int	my_exit(int err_num)
{
	if (err_num == -1)
		ft_putstr_fd("Error\n", 1);
	exit (0);
}

int	check_numbers(char *set, char ***splitted)
{
	unsigned int	index;
	unsigned int	number;

	index = 0;
	*splitted = ft_split(set, ' ');
	while ((*splitted)[index])
	{
		number = -1;
		while((*splitted)[index][++number])
		{
			if (number == 0 && (*splitted)[index][number] == '-')
				number++;
			if (!isdigit((*splitted)[index][number]))
				return (0);
		}
		index++;
	}
	return (1);
}

int	check_doubles(char **set)
{
	unsigned int	counter;

	while (*set)
	{
		counter = 1;
		while (set[counter])
		{
			if (!ft_strncmp(set[0], set[counter], ft_strlen(set[0])))
				return (0);
			counter++;
		}
		set++;
	}
	return (1);
}

int	*casher(char **set, int *save)
{
	unsigned int	counter;
	unsigned int 	index;
	int 			*cash;

	while (set[counter])
		counter++;
	cash = (int *)malloc(sizeof(int *) * counter);
	if (!cash)
		my_exit(-1);
	*save = counter;
	index = 0;
	while (set[index])
	{
		cash[index] = ft_atoi_long(set[index]);
		if (cash[index] > 2147483647 || cash[index] < -2147483648)
		{
			// написать функцию Free для массива интов
			my_exit(-1);
		}
		index++;
	}
	return (cash);
}

int	main(int argc, char *argv[])
{
	char	**set;
	int		*cash;
	int		counter;

	if (argc != 2 || !check_numbers(argv[1], &set) || !check_doubles(set))
		my_exit(-1);
	cash = casher(set, &counter);
	stacker(cash, counter);
	while (*set)
	{
		write(1, *set, ft_strlen(*set));
		write(1, "\n", 1);
		set++;
	}
	return (0);
}
