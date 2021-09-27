#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../includes/libft.h"
typedef struct linked_list
{
	int					number;
	char 				head;
	struct linked_list	*next;
	struct linked_list	*previous;
}	t_stack;

long int	ft_atoi_long(const char *str);
int			my_exit(int err_num);
void		stack_init(int *cash, int counter);
void		print_stack(t_stack *stack);
void		swap_a_b(t_stack *stack_A, char *set);
void		swap_both(t_stack *stack_a, t_stack *stack_b);

void		roundlst_addfront(t_stack **lst, t_stack *new);
void		roundlst_addback(t_stack **lst, t_stack *new);
void		roundlst_delfirst(t_stack **stack);

void		push_a(t_stack **stack_B, t_stack **stack_A);
void		push_b(t_stack **stack_A, t_stack **stack_B);

void		shift_A(t_stack **stack);
void		shift_B(t_stack **stack);
void		shift_both(t_stack **stack_A, t_stack **stack_B);

void		reverse_shift_A(t_stack **stack);
void		reverse_shift_B(t_stack **stack);
void		reverse_shift_both(t_stack **stack_A, t_stack **stack_B);

t_stack		*lstnew(int content, char head);
int			len_stack(t_stack *stack);

#endif
