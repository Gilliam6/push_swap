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
	int	len;
	t_stack *last;

//	write(1, "hi", 2);

	len = len_stack(*lst);
	if (!new)
		return ;
	else if (!len)
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

	last = (*stack)->previous;
	if (!(*stack))
		return ;
	else if ((*stack)->number == (*stack)->next->number)
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
		last->previous = *stack;
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
	push_b(&stack_A, &stack_B);
	push_b(&stack_A, &stack_B);
	push_a(&stack_B, &stack_A);
	push_a(&stack_B, &stack_A);

	write(1, "\nstack A\n", 9);
	print_stack(stack_A);
	write(1, "\nstack B\n", 9);
	print_stack(stack_B);
//	printf("number = %d | head = %d\n", stack_B->number, stack_B->head);
//	stack_B = stack_B->next;
//	printf("number = %d | head = %d\n", stack_B->number, stack_B->head);

}

