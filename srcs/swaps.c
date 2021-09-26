#include "../includes/push_swap.h"

void	swap_a_b(t_stack *stack_a, char *action)
{
	int	tmp;

	if (stack_a->next)
	{
		tmp = stack_a->next->number;
		stack_a->next->number = stack_a->number;
		stack_a->number = tmp;
	}
	if (action)
		write(1, action, 3);
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap_a_b(stack_b, 0);
	swap_a_b(stack_a, 0);
	write(1, "ss\n", 3);
}