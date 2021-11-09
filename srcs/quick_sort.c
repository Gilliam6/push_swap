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

void	push_half(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	int	len;

	len = len_stack(*stack_A);
	while (len--)
	{
		if ((*stack_A)->order <= orders->mid && !(*stack_A)->group)
			push_b(stack_A, stack_B);
		else
			shift_A(stack_A);
	}
	orders->max = orders->mid;
	orders->mid = (orders->max - orders->next) / 2 + orders->next;
	orders->group++;
}

int 	check_tops(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	if ((*stack_B)->order == orders->next)
	{
		push_a(stack_B, stack_A);
		(*stack_A)->group = orders->group;
		shift_A(stack_A);
		orders->next++;
		return (1);
	}

	return (0);

}

void	push_back(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	int	len;

	len = len_stack(*stack_B);
	while (len--)
	{
		if (check_tops(stack_A, stack_B, orders));
		else
		{
			if ((*stack_B)->order >= orders->mid)
			{
				(*stack_B)->group = orders->group;
				push_a(stack_B, stack_A);
			}
			else
			{
				shift_B(stack_B);
			}
		}
	}
	orders->max = orders->mid;
	orders->mid = (orders->max - orders->next) / 2 + orders->next;
	orders->group++;
}

int	shift_optimizer(t_stack *stack, int mid, t_medians *orders)
{
	int i;

	i = 0;
	while (stack->order != orders->next)
	{
		stack = stack->next;
		i++;
	}
	return (i < mid);
}

void	sort_group(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	int	len;

	len = len_stack(*stack_B);
	while (*stack_B)
	{
			if ((*stack_B)->order == orders->next)
			{
				(*stack_B)->group = orders->group;
				push_a(stack_B, stack_A);
				shift_A(stack_A);
				orders->next++;
				len--;
			}
			else if (shift_optimizer(*stack_B, len / 2, orders))
				shift_B(stack_B);
			else
				reverse_shift_B(stack_B);
	}
}

int	group_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->group == stack->next->group)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

//void groups_optimizer(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
//{
//
//}
void	first_push_and_back(t_stack **stack_A, t_stack **stack_B, t_medians
*orders)
{
	push_half(stack_A, stack_B, orders);
	while (*stack_B)
		push_back(stack_A, stack_B, orders);
	while ((*stack_A)->group)
	{
		while ((*stack_A)->group == (*stack_A)->next->group)
			push_b(stack_A, stack_B);
		push_b(stack_A, stack_B);
		sort_group(stack_A, stack_B, orders);
	}

	orders->max = len_stack(*stack_A);
	orders->mid = (orders->max - orders->next) / 2 + orders->next - 2;
}

void	quick_sort(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	first_push_and_back(stack_A, stack_B, orders);
	while (!(*stack_A)->group)
	{
		if ((*stack_A)->order <= orders->mid)
			push_b(stack_A, stack_B);
		else
			shift_A(stack_A);
	}
	while (!(*stack_A)->previous->group)
	{
		if ((*stack_B)->order != orders->next)
			reverse_shift_both(stack_A, stack_B);
		else
			reverse_shift_A(stack_A);
	}
	sort_group(stack_A, stack_B, orders);
	orders->mid = (orders->max - orders->next) / 2 + orders->next;
//	printf("next %d| max %d| mid %d\n", orders->next, orders->max, orders->mid);
	while (!(*stack_A)->group)
	{
		if ((*stack_A)->order <= orders->mid)
			push_b(stack_A, stack_B);
		else
			shift_A(stack_A);
	}
	orders->mid = (orders->max - orders->next) / 2 + orders->next;
	while ((*stack_A)->previous->order > orders->next)
	{
		if ((*stack_B)->order != orders->next)
			reverse_shift_both(stack_A, stack_B);
		else
			reverse_shift_A(stack_A);
	}
	sort_group(stack_A, stack_B, orders);
	while (!(*stack_A)->group)
	{
		push_b(stack_A, stack_B);
	}
	sort_group(stack_A, stack_B, orders);
}
