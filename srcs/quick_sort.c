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

//int	find_median(t_stack *stack)
//{
//	int median;
//	if (len_stack(stack) >= 15)
//		median = median_On(stack);
//	else
//		median = median_low(stack);
//	return (median);
//}

void	push_half(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	int	len;

	len = len_stack(*stack_A);

	while (len--)
	{
		if ((*stack_A)->order <= orders->mid)
			push_b(stack_A, stack_B);
		else
			shift_A(stack_A);
	}
	orders->max = orders->mid;
	orders->mid = (orders->max - orders->next) / 2 + orders->next;
	orders->group++;
}

int	check_tops(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	if ((*stack_A)->order == orders->next)
	{
		shift_A(stack_A);
		orders->next++;
		return (1);
	}
	if ((*stack_B) && (*stack_B)->order == orders->next)
	{
		(*stack_B)->group = orders->group;
		push_a(stack_B, stack_A);
		shift_A(stack_A);
		orders->next++;
		return (1);
	}
	if ((*stack_B) && (*stack_B)->previous->order == orders->next)
	{
		reverse_shift_B(stack_B);
		(*stack_B)->group = orders->group;
		push_a(stack_B, stack_A);
		shift_A(stack_A);
		orders->next++;
		return (1);
	}
	return (0);
}

void	push_back(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	int	len;

	len = len_stack(*stack_A);
	while (len--)
	{
		if ((*stack_A)->order <= orders->mid)
		{
			(*stack_A)->group = orders->group;
			push_b(stack_A, stack_B);
			if ((*stack_B)->order == orders->next)
			{
				orders->next++;
				shift_B(stack_B);
			}
		}
		else
			shift_A(stack_A);
		check_tops(stack_B, stack_A, orders);
	}
	orders->max = orders->mid;
	orders->mid = (orders->max - orders->next) / 2 + orders->next;
	orders->group++;
//	if (*stack_B)
//		check_tops(stack_B, stack_A, orders);
}

void quick_sort(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	while (!sorted_stack(*stack_A) && !(*stack_B))
	{
		if (!(*stack_B))
			push_half(stack_A, stack_B, orders);
//		printf("orders mid %d | max %d | next %d\n", orders->mid, orders->max,
//			orders->next);
		while (*stack_B)
			push_back(stack_B, stack_A, orders);
		while (check_tops(stack_A, stack_B, orders));
	}
}