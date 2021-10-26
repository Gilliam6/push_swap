#include "../includes/push_swap.h"

void	shift_A(t_stack **stack)
{
	if (len_stack(*stack) > 1)
	{
		(*stack)->next->head = 1;
		(*stack)->head = 0;
		(*stack) = (*stack)->next;
	}
	write(1, "ra\n", 3);
}

void	shift_B(t_stack **stack)
{
	if (len_stack(*stack) > 1)
	{
		(*stack)->next->head = 1;
		(*stack)->head = 0;
		(*stack) = (*stack)->next;
	}
	write(1, "rb\n", 3);
}

void	shift_both(t_stack **stack_A, t_stack **stack_B)
{
	if (len_stack(*stack_A) > 1)
	{
		(*stack_A)->next->head = 1;
		(*stack_A)->head = 0;
		(*stack_A) = (*stack_A)->next;
	}
	if (len_stack(*stack_B) > 1)
	{
		(*stack_B)->next->head = 1;
		(*stack_B)->head = 0;
		(*stack_B) = (*stack_B)->next;
	}
	write(1, "rr\n", 3);
}