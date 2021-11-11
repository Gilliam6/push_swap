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

void	push_back(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	int	len;

	len = len_stack(*stack_B);
	while (len--)
	{
		if ((*stack_B)->order == orders->next)
		{
			push_a(stack_B, stack_A);
			(*stack_A)->group = orders->group;
			shift_A(stack_A);
			orders->next++;
		}
		else if ((*stack_B)->order >= orders->mid)
		{
			(*stack_B)->group = orders->group;
			push_a(stack_B, stack_A);
		}
		else
			shift_B(stack_B);
	}
//	sort_3(stack_B);
//	while (*stack_B)
//	{
//		push_a(stack_B, stack_A);
//		(*stack_A)->group = orders->group;
//		shift_A(stack_A);
//		orders->next++;
//	}
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
void	sort_3_5_in_act(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	sort_3_b(stack_B);
	while (*stack_B)
	{
		push_a(stack_B, stack_A);
		(*stack_A)->group = orders->group;
		shift_A(stack_A);
		orders->next++;
	}
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
				if (len_stack(*stack_B) == 3)
					sort_3_5_in_act(stack_A, stack_B, orders);
			}
			else if (shift_optimizer(*stack_B, len / 2, orders))
				shift_B(stack_B);
			else
				reverse_shift_B(stack_B);
	}
}



void	reversoid(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	while ((*stack_A)->previous->order > orders->next)
	{
		if ((*stack_B)->order != orders->next)
			reverse_shift_both(stack_A, stack_B);
		else
			reverse_shift_A(stack_A);
	}
	sort_group(stack_A, stack_B, orders);
	orders->mid = (orders->max - orders->next) / 2 + orders->next;
}

void	small_banch_optimization(t_stack **stack_A, t_stack **stack_B,
							  t_medians *orders)
{
	int	group;

	group = group_size(*stack_A, (*stack_A)->group);
	if (group <= 3)
		opt_3(stack_A, stack_B, orders);
	else
	{
		kick_max_to_b(stack_A, stack_B, orders, group - 3);
		opt_3(stack_A, stack_B, orders);
		take_max_to_a(stack_A, stack_B, orders);
		opt_3(stack_A, stack_B, orders);
	}
}

void	push_ungroupped_halfs(t_stack **stack_A, t_stack **stack_B, t_medians
*orders)
{
	while (!(*stack_A)->group)
	{
		if ((*stack_A)->order <= orders->mid)
		{
			if ((*stack_A)->order < (orders->next + orders->mid) / 2)
				push_b(stack_A, stack_B);
			else
			{
				push_b(stack_A, stack_B);
				shift_B(stack_B);
			}
		}
		else
			shift_A(stack_A);
	}
}

int	group_size(t_stack *stack, int group)
{
	int i;

	i = 0;

	while (stack->group == group)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	first_push_and_back(t_stack **stack_A, t_stack **stack_B, t_medians
*orders)
{
	push_half(stack_A, stack_B, orders);
	while (*stack_B)
		push_back(stack_A, stack_B, orders);
	while ((*stack_A)->group)
	{
		if (group_size(*stack_A, (*stack_A)->group) <= 6)
			small_banch_optimization(stack_A, stack_B, orders);
		else
		{
			while ((*stack_A)->group == (*stack_A)->next->group)
			{
				if ((*stack_A)->order == orders->next)
				{
					shift_A(stack_A);
					orders->next++;
				} else
					push_b(stack_A, stack_B);
			}
			push_b(stack_A, stack_B);
			sort_group(stack_A, stack_B, orders);
		}
	}
	orders->max = len_stack(*stack_A);
	orders->mid = (orders->max - orders->next) / 2 + orders->next + 1;
}

void	quick_sort(t_stack **stack_A, t_stack **stack_B, t_medians *orders)
{
	first_push_and_back(stack_A, stack_B, orders);
	while (!sorted_stack(*stack_A))
	{
//		if (orders->mid - orders->next <= 3)
//		{
//			ft_putstr_fd("stack A\n", 1);
//			print_stack(*stack_A);
//			ft_putstr_fd("stack B\n", 1);
//			print_stack(*stack_B);
//			printf("mid | %d, next | %d", orders->mid, orders->next);
//			sleep(50);
//			if (orders->mid - orders->next == 1)
//			{
//				(*stack_A)->group = orders->group;
//				shift_A(stack_A);
//				orders->next++;
//			}
//			if (orders->mid - orders->next == 2)
//			{
//				if ((*stack_A)->order > (*stack_A)->next->order)
//					swap_a(stack_A);
//				(*stack_A)->group = orders->group;
//				shift_A(stack_A);
//				orders->next++;
//				(*stack_A)->group = orders->group;
//				shift_A(stack_A);
//				orders->next++;
//			}
////			small_banch_optimization(stack_A, stack_B, orders);
//			orders->mid = (orders->max - orders->next) / 2 + orders->next;
//			ft_putstr_fd("stack A\n", 1);
//			print_stack(*stack_A);
//			ft_putstr_fd("stack B\n", 1);
//			print_stack(*stack_B);
//			printf("mid | %d, next | %d", orders->mid, orders->next);
//		}
//		if (group_size(*stack_A, 0) <= 5)
//			small_banch_optimization(stack_A, stack_B, orders);
		push_ungroupped_halfs(stack_A, stack_B, orders);
		reversoid(stack_A, stack_B, orders);
	}
//	push_ungroupped_halfs(stack_A, stack_B, orders);
//	reversoid(stack_A, stack_B, orders);
//	while (!(*stack_A)->group)
//		push_b(stack_A, stack_B);
//	sort_group(stack_A, stack_B, orders);
}

