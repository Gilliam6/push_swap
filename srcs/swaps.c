#include "../includes/push_swap.h"

void	swap_a(t_stack **stack_a)
{
	int	tmp;

	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = (*stack_a)->next->number;
		(*stack_a)->next->number = (*stack_a)->number;
		(*stack_a)->number = tmp;
	}
	write(1, "sa\n", 3);
}
void	swap_b(t_stack **stack_b)
{
	int	tmp;

	if ((*stack_b) && (*stack_b)->next)
	{
		tmp = (*stack_b)->next->number;
		(*stack_b)->next->number = (*stack_b)->number;
		(*stack_b)->number = tmp;
	}
	write(1, "sb\n", 3);
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	write(1, "ss\n", 3);
}