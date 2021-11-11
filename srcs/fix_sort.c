#include "../includes/push_swap.h"

void 	sort_3_a(t_stack **stack)
{
	if ((*stack)->order > (*stack)->next->order)
		swap_a(stack);
	if ((*stack)->order > (*stack)->previous->order)
		reverse_shift_A(stack);
	if ((*stack)->next->order > (*stack)->previous->order)
	{
		swap_a(stack);
		shift_A(stack);
	}
}

void 	sort_3_b(t_stack **stack)
{
	if ((*stack)->order > (*stack)->next->order)
		swap_b(stack);
	if ((*stack)->order > (*stack)->previous->order)
		reverse_shift_B(stack);
	if ((*stack)->next->order > (*stack)->previous->order)
	{
		swap_b(stack);
		shift_B(stack);
	}
}

void 	sort_4(t_stack **stack_A, t_stack **stack_B)
{
	while ((*stack_A)->order != 1)
		shift_A(stack_A);
	push_b(stack_A, stack_B);
	sort_3_a(stack_A);
	push_a(stack_B, stack_A);
}

void 	sort_5(t_stack **stack_A, t_stack **stack_B)
{
	int len;

	len = 2;
	while (len)
	{
		if ((*stack_A)->order < 3)
		{
			push_b(stack_A, stack_B);
			len--;
		}
		else
			shift_A(stack_A);
	}
	if ((*stack_B)->order < (*stack_B)->next->order)
		swap_b(stack_B);
	sort_3_a(stack_A);
	while (*stack_B)
		push_a(stack_B, stack_A);
//	print_stack(*stack_A);
}

int	find_mid(t_stack *stack_B)
{
	int min;

	min = stack_B->order;
	stack_B = stack_B->next;
	while (stack_B->head != 1)
	{
		if (min > stack_B->order)
			min = stack_B->order;
		stack_B = stack_B->next;
	}
	return (min + 2);
}

void 	sort_5_in_act(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	int mid;

	mid = find_mid(*stack_B);
	while (len_stack(*stack_B) > 3)
	{
		if ((*stack_B)->order < mid)
			push_a(stack_B, stack_A);
		else
			shift_B(stack_B);
	}
	if ((*stack_A)->order > (*stack_A)->next->order)
	{
		if ((*stack_B)->order > (*stack_B)->next->order)
			swap_both(stack_A, stack_B);
		else
			swap_a(stack_A);
	}
	shift_A(stack_A);
	shift_A(stack_A);
	orders->next += 2;
	sort_3_b(stack_B);
	while (*stack_B)
	{
		push_a(stack_B, stack_A);
		shift_A(stack_A);
		orders->next++;
	}
}
//void 	sort_6(t_stack **stack_A, t_stack **stack_B)
//{
//
//}