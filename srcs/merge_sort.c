#include "../includes/push_swap.h"
int	sorted_stack(t_stack *stack)
{
	t_stack		*last;

	last = stack->previous;
	while (stack->number != last->number)
	{
		if (stack->number > stack->next->number)
			break ;
		stack = stack->next;
	}
	if (stack->number > stack->next->number)
		return (0);
	return (1);
}

void first_comparison(t_stack **stack_A, t_stack **stack_B)
{
	int len;

	len = len_stack(*stack_A) / 2;
	while (len--)
	{
		if ((*stack_A)->next->number < (*stack_A)->number)
		{
			swap_a(stack_A);
			push_b(stack_A, stack_B);
		}
		else
			push_b(stack_A, stack_B);
		shift_A(stack_A);
	}
}

void merge_sort(t_stack **stack_A, t_stack **stack_B)
{
//	t_stack *last;
//
//	last = (*stack_A)->previous;
	if (!(*stack_B))
		first_comparison(stack_A, stack_B);
	while (!sorted_stack(*stack_A))
	{
		if (((*stack_A)->number) > ((*stack_A)->next->number))
			swap_a(stack_A);
		reverse_shift_A(stack_A);
	}
//	while (!sorted_stack(*stack_B))
//	{
//		if (((*stack_B)->number) > ((*stack_B)->next->number))
//			swap_b(stack_B);
//		reverse_shift_B(stack_B);
//	}
}