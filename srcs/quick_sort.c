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


int	check_tops(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	if ((*stack_A)->order == orders->next)
	{
		shift_A(stack_A);
		orders->next++;
		return (1);
	}
//	if ((*stack_A)->next->order == orders->next)
//	{
//		push_b(stack_A, stack_B);
//		shift_A(stack_A);
//		push_a(stack_B, stack_A);
//	}
	if ((*stack_B) && (*stack_B)->order == orders->next)
	{
		(*stack_B)->group = orders->group;
		push_a(stack_B, stack_A);
		shift_A(stack_A);
		orders->next++;
		return (1);
	}
//	if ((*stack_B) && (*stack_B)->previous->order == orders->next)
//	{
//		reverse_shift_B(stack_B);
//		(*stack_B)->group = orders->group;
//		push_a(stack_B, stack_A);
//		shift_A(stack_A);
//		orders->next++;
//		return (1);
//	}
	return (0);
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

void 	sort_3(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	if ((*stack_B)->next->order == orders->next)
	{
		swap_b(stack_B);
		(*stack_B)->group = orders->group;
		push_a(stack_B, stack_A);
		shift_A(stack_A);
	}
	check_tops(stack_A, stack_B, orders);
}

void	push_back(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	int	len;

	len = len_stack(*stack_B);
	while (len--)
	{
		if ((*stack_B)->order >= orders->mid)
		{
			(*stack_B)->group = orders->group;
			push_a(stack_B, stack_A);
			if ((*stack_A)->order == orders->next)
			{
				orders->next++;
				shift_A(stack_A);
			}
		}
		else
			shift_B(stack_B);
//		if ((*stack_B) && check_tops(stack_A, stack_B, orders))
//			len--;
	}
	orders->max = orders->mid;
	orders->mid = (orders->max - orders->next) / 2 + orders->next;
	orders->group++;

}

void quick_sort(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{

	push_half(stack_A, stack_B, orders);
	while (*stack_B)
		push_back(stack_A, stack_B, orders);
//	push_back(stack_A, stack_B, orders);
	printf("orders mid %d | max %d | next %d\n", orders->mid, orders->max,
		   orders->next);
	while (check_tops(stack_A, stack_B, orders));
	while((*stack_A)->group == (*stack_A)->next->group)
	{
		check_tops(stack_A, stack_B, orders);
		push_b(stack_A, stack_B);
	}
	check_tops(stack_A, stack_B, orders);
//	push_b(stack_A, stack_B);
//	while (*stack_B)
//	{
//		push_a(stack_B, stack_A);
//		check_tops(stack_A, stack_B, orders);
//	}
	printf("orders mid %d | max %d | next %d\n", orders->mid, orders->max,
		   orders->next);
}