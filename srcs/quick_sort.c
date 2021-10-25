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
		if ((*stack_A)->order <= orders->mid && !(*stack_A)->group)
			push_b(stack_A, stack_B);
		else
			shift_A(stack_A);
	}
	orders->max = orders->mid;
	orders->mid = (orders->max - orders->next) / 2 + orders->next;
	orders->group++;
}

void	sort_2(t_stack **stack)
{
	if ((*stack)->order > (*stack)->next->order)
		swap_b(stack);
}

void 	sort_3(t_stack **stack)
{
	if ((*stack)->order > (*stack)->next->order)
		swap_b(stack);
	if ((*stack)->order > (*stack)->previous->order)
		reverse_shift_B(stack);
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
		{
			shift_B(stack_B);
//			check_tops(stack_A, stack_B, orders);
		}
//		if ((*stack_B) && check_tops(stack_A, stack_B, orders))
//			len--;
	}
	orders->max = orders->mid;
	orders->mid = (orders->max - orders->next) / 2 + orders->next;
	orders->group++;

}

void	sort_group(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	int	len;

	len = len_stack(*stack_B);
	if (len == 2)
		sort_2(stack_B);
	else if (len == 3)
		sort_3(stack_B);
	while (*stack_B)
	{
		if ((*stack_B)->order == orders->next)
		{
			push_a(stack_B, stack_A);
			shift_A(stack_A);
			orders->next++;
			len--;
		}
		else
		{
//			printf("next %d | order %d\n", orders->next, (*stack_B)->order);
//			write(1, "STACK A\n", 8);
//			print_stack(*stack_A);
//			write(1, "STACK B\n", 8);
//			print_stack(*stack_B);
			shift_B(stack_B);
		}
	}
}

void quick_sort(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	push_half(stack_A, stack_B, orders);
	while (*stack_B)
		push_back(stack_A, stack_B, orders);
	write(1, "\nstack A\n", 9);
	print_stack(*stack_A);
	write(1, "\nstack B\n", 9);
	print_stack(*stack_B);
	while ((*stack_A)->group)
	{
		while ((*stack_A)->group == (*stack_A)->next->group)
			push_b(stack_A, stack_B);
		push_b(stack_A, stack_B);
		sort_group(stack_A, stack_B, orders);
	}

	orders->max = len_stack(*stack_A);
	orders->mid = (orders->max - orders->next) / 2 + orders->next;
	while (!(*stack_A)->group)
	{
//		if ((*stack_A)->order == orders->next)
//		{
//			shift_A(stack_A);
//			orders->next++;
//		}
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
	while (!(*stack_A)->group)
			push_b(stack_A, stack_B);
	sort_group(stack_A, stack_B, orders);
	//	push_b(stack_A, stack_B);
//	while (*stack_B)
//	{
//		push_a(stack_B, stack_A);
//		check_tops(stack_A, stack_B, orders);
//	}
//	printf("orders mid %d | max %d | next %d\n", orders->mid, orders->max,
//		   orders->next);
}