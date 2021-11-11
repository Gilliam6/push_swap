#include "../includes/push_swap.h"

void	opt_3(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	if ((*stack_A)->order != orders->next)
		push_b(stack_A, stack_B);
	if ((*stack_A)->order > (*stack_A)->next->order)
		swap_a(stack_A);
	else
	{
		while ((*stack_A)->order == orders->next)
		{
			shift_A(stack_A);
			orders->next++;
		}
	}
	if ((*stack_B) && (*stack_B)->order == orders->next)
	{
		push_a(stack_B, stack_A);
		shift_A(stack_A);
		orders->next++;
	}
	if ((*stack_A)->order == orders->next)
	{
		shift_A(stack_A);
		orders->next++;
	}
}

void	kick_max_to_b(t_stack **stack_A, t_stack **stack_B, t_medians
*orders, int len)
{
	int i;
	i = 0;

	while (len)
	{
		if ((*stack_A)->order >= orders->next + 3)
		{
			push_b(stack_A, stack_B);
			len--;
		}
		else
		{
			shift_A(stack_A);
			i++;
		}
	}
	while (i--)
	{
		if ((*stack_B)->order != orders->next)
			reverse_shift_both(stack_A, stack_B);
		else
			reverse_shift_A(stack_A);
	}
}

void	take_max_to_a(t_stack **stack_A, t_stack **stack_B, t_medians
*orders)
{
	while (*stack_B)
	{
		push_a(stack_B, stack_A);
		if ((*stack_A)->order == orders->next)
		{
			shift_A(stack_A);
			orders->next++;
		}
	}
}