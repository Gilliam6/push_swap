#include "../includes/push_swap.h"

t_stack	*lstnew(int content, char head)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		my_exit(-1);
	new_node->number = content;
	new_node->head = head;
	new_node->next = 0;
	new_node->previous = 0;
	return (new_node);
}

void	roundlst_addback(t_stack **lst, t_stack *new)
{
	t_stack	*begin;

	if (!new)
		return ;
	if (*lst)
	{
		begin = *lst;
		while ((*lst)->next && !(*lst)->next->head)
			*lst = (*lst)->next;
		(*lst)->next = new;
		new->next = begin;
		new->previous = *lst;
		*lst = begin;
	}
	else
		*lst = new;
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

void	stacker(int *cash, int counter)
{
	t_stack	*stack_A;
//	t_stack	*stack_B;

	stack_A = stack_constructor(cash, counter);
	while (counter--)
	{
		printf("number = %d | head = %d\n", stack_A->number, stack_A->head);
		stack_A	= stack_A->next;
	}
}

