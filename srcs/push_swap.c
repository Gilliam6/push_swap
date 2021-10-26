#include "../includes/push_swap.h"

int	my_exit(int err_num)
{
	if (err_num == -1)
		ft_putstr_fd("Error\n", 1);
	if (err_num == -2)
		ft_putstr_fd("Malloc problem\n", 1);
	exit (0);
}

int	*casher(char **set, int *save)
{
	unsigned int	counter;
	unsigned int 	index;
	long int 		tmp;
	int 			*cash;

	counter = 0;
	while (set[counter])
		counter++;
	cash = (int *)malloc(sizeof(int *) * counter);
	if (!cash)
		my_exit(-1);
	*save = counter;
	index = 0;
	while (set[index])
	{
		tmp = ft_atoi_long(set[index]);
		if (tmp > 2147483647 || tmp < -2147483648)
		{
			// написать функцию Free для массива интов
			my_exit(-1);
		}
		cash[index] = tmp;
		index++;
	}
	return (cash);
}

int	main(int argc, char **argv)
{
	char **set;
	int *cash;
	int counter;

	set = 0;
	counter = 0;
	if (argc == 2)
	{
		if (!check_numbers(argv[1], &set) || !check_doubles(set))
		{
			my_exit(-1);
		}
	}
	else
	{
		if (!check_numbers_wo_split(++argv) || !check_doubles(argv))
			my_exit(-1);
	}
	if (set == 0)
		cash = casher(argv, &counter);
	else
	{
		cash = casher(set, &counter);
	}
	if (!stack_init(cash, counter))
	{
		my_exit(-2);
	}
//	write(1, "\ncheck input\n", 13);
//	while (*set)
//	{
//		write(1, *set, ft_strlen(*set));
//		write(1, "\n", 1);
//		set++;
//	}
	return (0);
}
