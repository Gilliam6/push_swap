#include "../includes/push_swap.h"

int array_solver(int *array, int index)
{
	int	mid;
	int len;

	len = 5;
	mid = 0;
	while(len--)
		if (array[index] < array[len])
			mid++;
	return (mid);
}

int	median_of_5(int index, t_stack *stack)
{
	int start;
	int	array[5];

	start = index * 5;
	while (start--)
		stack = stack->next;
	while (start < 5)
	{
		array[start] = stack->number;
		start++;
		stack = stack->next;
	}
	while (start--)
		if (array_solver(array, start) == 2)
			return (array[start]);
	return (my_exit(0));
}

int median_of_median(int *med_5, int len, int index)
{
	int	mid;

	mid = 0;
	while (len--)
	{
		if (med_5[index] < med_5[len])
			mid++;
	}
	return (mid);
}

int 	median_On(t_stack *stack)
{
	int	len;
	int *med_5;
	int	index;
	int	mid;

	len = len_stack(stack) / 5;
	med_5 = malloc(sizeof(int) * len);
	index = 0;
	while (index < 5)
	{
		med_5[index] = median_of_5(index, stack);
		index++;
	}
	index = 0;
	while (index < len)
	{
		mid = median_of_median(med_5, len, index);
		if (mid == len / 2)
			return (med_5[index]);
		index++;
	}
	return (my_exit(0));
}

int		median_low(t_stack *stack)
{
	int len;
	int *medians;
	int	index;
	int mid;

	len = len_stack(stack);
	medians = malloc(sizeof(int) * len);
	if (!medians)
		return (my_exit(0));
	index = 0;
	while (index < len)
	{
		medians[index] = stack->number;
		index++;
		stack = stack->next;
	}
	while (index--)
	{
		mid = median_of_median(medians, len, index);
		if (mid == len / 2)
		{
			mid = medians[index];
			free(medians);
			return (mid);
		}
	}
	return (0);
}