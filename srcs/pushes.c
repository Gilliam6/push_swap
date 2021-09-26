#include "../includes/push_swap.h"

void push_b(t_stack **stack_A, t_stack **stack_B)
{
	roundlst_addfront(stack_B, lstnew((*stack_A)->number, (*stack_A)->head));
//	write(1, "hi", 2);
	roundlst_delfirst(stack_A);
}