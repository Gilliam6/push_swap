#include "../includes/push_swap.h"

int	sorted_stack(t_stack *stack)
{
	int last;

	last = stack->previous->number;
	while (stack->number != last)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_median(t_stack *stack)
{
	int median;
	if (len_stack(stack) >= 15)
		median = median_On(stack);
	else
		median = median_low(stack);
	return (median);
}

void push_medians(t_stack **stack_A, t_stack **stack_B, int mid, int groups)
{
	int	len;

	len = len_stack(*stack_A);
	while (len--)
	{
		if ((*stack_A)->number <= mid)
		{
			(*stack_A)->group = groups;
			push_b(stack_A, stack_B);
		}
		else
			shift_A(stack_A);
	}
}

void push_medians_back(t_stack **stack_A, t_stack **stack_B, int mid, int
groups)
{
	int	len;

	len = len_stack(*stack_A);
	if (len > 3)
	{

		ft_putnbr_fd(len, 1);
		write(1, " len\n", 5);
		while (len--)
		{
			if ((*stack_B)->group == (*stack_B)->next->group && (*stack_B)
			->number > (*stack_B) ->next->number)
				swap_b(stack_B);
			if ((*stack_A)->number <= mid)
			{
				(*stack_A)->group = groups;
				push_b(stack_A, stack_B);
			}
			else
				shift_A(stack_A);
		}
	}
	else
	{
		while (len--)
		{
			if ((*stack_B)->group == (*stack_B)->next->group && (*stack_B)->number > (*stack_B)->next->number)
				swap_b(stack_B);
			(*stack_A)->group = groups;
			push_b(stack_A, stack_B);
		}
		if ((*stack_B)->group == (*stack_B)->next->group && (*stack_B)->number > (*stack_B)->next->number)
			swap_b(stack_B);
	}
	while ((*stack_B)->group == groups)
		shift_B(stack_B);
}

void quick_sort(t_stack **stack_A, t_stack **stack_B)
{
	int groups;

	groups = 0;
	push_medians(stack_A, stack_B, find_median(*stack_A), groups++);
	printf("median of stack A | %d\n", find_median(*stack_B));
	while ((*stack_B))
		push_medians_back(stack_B, stack_A, find_median(*stack_B), groups++);
	
//	printf("median of stack A | %d\n", median);
//	(void) stack_A;
//	(void) stack_B;

}