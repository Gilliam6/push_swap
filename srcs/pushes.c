#include "../includes/push_swap.h"

void push_b(t_stack **stack_A, t_stack **stack_B)
{
	roundlst_addfront(stack_B, lstnew((*stack_A)->number,1));
	roundlst_delfirst(stack_A);
	write(1, "pb\n", 3);
}

void push_a(t_stack **stack_B, t_stack **stack_A)
{
	roundlst_addfront(stack_A, lstnew((*stack_B)->number,1));
	roundlst_delfirst(stack_B);
	write(1, "pa\n", 3);
}