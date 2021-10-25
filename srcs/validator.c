#include "../includes/push_swap.h"

int	check_numbers(char *set, char ***splitted)
{
	unsigned int	index;
	unsigned int	number;
	char			**split;

	index = 0;
	split = ft_split(set, ' ');
	while (split[index])
	{
		number = -1;
		while(split[index][++number])
		{
			if (number == 0 && split[index][number] == '-')
				number++;
			if (!isdigit(split[index][number]))
				return (0);
		}
		index++;
	}
	*splitted = split;
	return (1);
}

int check_numbers_wo_split(char **splitted)
{
	unsigned int	index;
	unsigned int	number;

	index = 0;
	while (splitted[index])
	{
		number = -1;
		while(splitted[index][++number])
		{
			if (number == 0 && splitted[index][number] == '-')
				number++;
			if (!isdigit(splitted[index][number]))
				return (0);
		}
		index++;
	}
	return (1);
}

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 == *s2);
}

int	check_doubles(char **set)
{
	unsigned int	counter;

	while (*set)
	{
		counter = 1;
		while (set[counter])
		{
			if (ft_strcmp(set[0], set[counter]))
				return (0);
			counter++;
		}
		set++;
	}
	return (1);
}