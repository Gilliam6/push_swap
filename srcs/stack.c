#include "../includes/push_swap.h"

t_stack	*lstnew(int content, char head, int group, int order)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		my_exit(-1);
	new_node->number = content;
	new_node->group = group;
	new_node->head = head;
	new_node->order = order;
	new_node->next = new_node;
	new_node->previous = new_node;
	return (new_node);
}

void	roundlst_addback(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	else if (!*lst)
		*lst = new;
	else
	{
		last = (*lst)->previous;
		new->next = *lst;
		(*lst)->previous = new;
		last->next = new;
		new->previous = last;
	}
}

void	roundlst_addfront(t_stack **lst, t_stack *new)
{
	t_stack *last;

	if (!new)
		return ;
	else if (!(*lst))
		*lst = new;
	else
	{
		last = (*lst)->previous;
		new->previous = last;
		new->next = *lst;
		last->next = new;
		(*lst)->previous = new;
		(*lst)->head = 0;
		*lst = new;
	}

}

void	roundlst_delfirst(t_stack **stack)
{
	t_stack *last;
	t_stack *tmp;

	if (!(*stack))
		return ;
	last = (*stack)->previous;
	if ((*stack)->number == (*stack)->next->number)
	{
		tmp = *stack;
		*stack = 0;
		free(tmp);
	}
	else
	{
		tmp = *stack;
		(*stack) = (*stack)->next;
		(*stack)->previous = last;
		last->next = *stack;
		(*stack)->head = 1;
		free(tmp);
	}
}

t_stack	*stack_constructor(int *cash, int counter)
{
	int				index;
	t_stack			*stack_A;

	index = 0;
	stack_A = lstnew(cash[index], 1, 0, 0);
	while (++index < counter)
		roundlst_addback(&stack_A, lstnew(cash[index], 0, 0, 0));
	return (stack_A);
}

t_medians	*pre_sorting(t_stack **stack_A, int *cash, int counter)
{
	t_medians	*orders;
	int			index;
	int			order;
	int			n;

	orders = malloc(sizeof(orders));
	if (!orders)
		return (0);
	index = 0;
	orders->max = 0;
	while (index < counter)
	{
		order = 0;
		n = 0;
		while (n < counter)
		{
			if (cash[index] > cash[n])
				order++;
			n++;
		}
		if (order + 1 > orders->max)
			orders->max = order + 1;
		(*stack_A)->order = order + 1;
		(*stack_A) = (*stack_A)->next;
		index++;
	}
	orders->next = 1;
	orders->group = 0;
	orders->mid = orders->max / 2 + orders->next;
	return (orders);
}

void little_sort(t_stack **stack_A, t_stack **stack_B)
{
	if (len_stack(*stack_A) == 3)
		sort_3(stack_A);
	else if (len_stack(*stack_A) == 4)
		sort_4(stack_A, stack_B);
	else if (len_stack(*stack_A) == 5)
		sort_5(stack_A, stack_B);
//	else if (len_stack(*stack_A) == 6)
//		sort_6(stack_A, stack_B);
}

int	stack_init(int *cash, int counter)
{
	t_stack		*stack_A;
	t_stack		*stack_B;
	t_medians	*orders;

	stack_B = 0;
	stack_A = stack_constructor(cash, counter);
	if (!sorted_stack(stack_A))
	{
		orders = pre_sorting(&stack_A, cash, counter);
		if (!orders)
			return (0);
	}
	else
		return (1);
	if (len_stack(stack_A) <= 5)
		little_sort(&stack_A, &stack_B);
	else
		quick_sort(&stack_A, &stack_B, orders);
	return (1);
}

