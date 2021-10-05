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

void merge_sort(t_stack **stack_A, t_stack **stack_B)
{
	int	len;
	int	group;

	len = len_stack(*stack_A);
	group = 1;
	while (len > 1)
	{
		push_b(stack_A, stack_B);
		(*stack_B)->group = group;
		push_b(stack_A, stack_B);
		(*stack_B)->group = group;
		if ((*stack_B)->number < (*stack_B)->next->number)
			swap_b(stack_B);
		len -= 2;
		group++;
	}
	group--;


	while ((*stack_B)->group == group)
		push_a(stack_B, stack_A);
	while ((*stack_A)->group == group)
	{
		if ((*stack_A)->number > (*stack_B)->number)
			push_a(stack_B, stack_A);
		else
			shift_A(stack_A);
	}
	while ((*stack_B)->group == group - 1)
	{
		push_a(stack_B, stack_A);
		(*stack_A)->group = group;
 	}
	if ((*stack_A)->number > (*stack_A)->next->number)
		swap_a(stack_A);
	while ((*stack_A)->previous->group == group)
		reverse_shift_A(stack_A);


	while (*stack_B && (*stack_A)->group == group)
	{
		if ((*stack_A)->number > (*stack_B)->number)
		{
			push_a(stack_B, stack_A);
			(*stack_A)->group = group;
		}
		else
			shift_A(stack_A);
	}
	while ((*stack_A)->previous->group == group)
		reverse_shift_A(stack_A);

	reverse_shift_A(stack_A);
	push_b(stack_A, stack_B);

	group = 0;
	while (*stack_B)
	{
		if ((*stack_B)->number < (*stack_A)->number)
			push_a(stack_B, stack_A);
		else
		{
			shift_A(stack_A);
			group++;
		}
	}

	while (group)
	{
		reverse_shift_A(stack_A);
		group--;
	}

//	while (!sorted_stack(*stack_A))
//		reverse_shift_A(stack_A);
//	while (*stack_B)
//	{
//
//	}
//	while (!sorted_stack(*stack_B))
//	{
//		if (((*stack_B)->number) > ((*stack_B)->next->number))
//			swap_b(stack_B);
//		reverse_shift_B(stack_B);
//	}
}