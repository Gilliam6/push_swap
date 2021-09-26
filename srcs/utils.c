#include "../includes/push_swap.h"

long int	ft_atoi_long(const char *str)
{
	long int	final;
	int			minus;

	minus = 1;
	final = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			minus = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		final *= 10;
		final += *str - 48;
		str++;
	}
	return (final * minus);
}

void print_stack(t_stack *stack)
{
	if (!stack)
	{
		write(1, "stack is nothing\n", 17);
		return ;
	}
	printf("number = %d | head = %d\n", stack->number, stack->head);
	stack = stack->next;
	while (stack->head == 0)
	{
		printf("number = %d | head = %d\n", stack->number, stack->head);
		stack = stack->next;
	}
}

int	len_stack(t_stack *stack)
{
	int len;

	len = 0;
	if (!stack)
		return (0);
	len++;
	stack = stack->next;
	while (stack->head == 0)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}