#include "../includes/push_swap.h"

t_stack	*lstnew(int content, char head)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		my_exit(-1);
	new_node->number = content;
	new_node->head = head;
	new_node->next = new_node;
	new_node->previous = new_node;
	return (new_node);
}

void	roundlst_addback(t_stack **lst, t_stack *new)
{
	t_stack	*begin;
	int		len;

	len = len_stack(*lst);
	if (!new)
		return ;
	else if (!len)
		*lst = new;
	else
	{
		begin = *lst;
		while ((*lst)->next && !(*lst)->next->head)
			*lst = (*lst)->next;
		(*lst)->next = new;
		new->next = begin;
		new->previous = *lst;
		*lst = begin;
	}
}

void	roundlst_addfront(t_stack **lst, t_stack *new)
{
	int	len;

	len = len_stack(*lst);
	if (!new)
		return ;
	else if (!len)
		*lst = new;
	else if (len == 1)
	{
		new->previous = *lst;
		new->next = *lst;
		(*lst)->next = new;
		(*lst)->previous = new;
		(*lst)->head = 0;
		*lst = new;
	}
	else
	{
		new->previous = (*lst)->previous;
		new->next = *lst;
		(*lst)->previous = new;
		(*lst)->head = 0;
		*lst = new;
	}
}

void	roundlst_delfirst(t_stack **stack)
{
	t_stack *tmp;
	int		len;

	len = len_stack(*stack);
	tmp = *stack;
	if (!len)
		return ;
	else if (len == 1)
	{
		*stack = 0;
		free(tmp);
	}
	else if (len == 2)
	{
		(*stack) = (*stack)->next;
		(*stack)->next = (*stack);
		(*stack)->previous = (*stack);
		(*stack)->head = 1;
		free(tmp);
	}
	else
	{
		(*stack) = (*stack)->next;
//		(*stack)->next = (*stack)->next;
		(*stack)->previous = (*stack)->previous->previous;
		(*stack)->previous->next = (*stack);
		(*stack)->head = 1;
		free(tmp);
	}
}

t_stack	*stack_constructor(int *cash, int counter)
{
	int				index;
	t_stack			*stack_A;

	index = 0;
	stack_A = lstnew(cash[index], 1);
	while (++index < counter)
		roundlst_addback(&stack_A, lstnew(cash[index], 0));
	return (stack_A);
}

void	stack_init(int *cash, int counter)
{
	t_stack	*stack_A;
	t_stack	*stack_B;

	stack_B = 0;

	stack_A = stack_constructor(cash, counter);

	print_stack(stack_A);
	swap_a_b(stack_A, "sa\n");
	print_stack(stack_A);
	swap_a_b(stack_A, "sa\n");
	print_stack(stack_A);
	write(1, "\n", 1);

	push_b(&stack_A, &stack_B);
	push_b(&stack_A, &stack_B);
//	push_b(&stack_A, &stack_B);
//	push_b(&stack_A, &stack_B);
//	push_b(&stack_A, &stack_B);

	write(1, "\nstack A\n", 9);
	print_stack(stack_A);
	write(1, "\nstack B\n", 9);
	print_stack(stack_B);
}

