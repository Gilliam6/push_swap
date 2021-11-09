#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../includes/libft.h"
typedef struct linked_list
{
	int					number;
	char 				head;
	int					order;
	int 				group;
	struct linked_list	*next;
	struct linked_list	*previous;
}	t_stack;

typedef struct medians
{
	int					next;
	int					mid;
	int 				max;
	int					group;
}	t_medians;

int			check_numbers(char *set, char ***splitted);
int			check_numbers_wo_split(char **splitted);
int			check_doubles(char **set);

void		little_sort(t_stack **stack_A, t_stack **stack_B);

void 		sort_5(t_stack **stack_A, t_stack **stack_B);
void 		sort_4(t_stack **stack_A, t_stack **stack_B);
void 		sort_3(t_stack **stack);


long int	ft_atoi_long(const char *str);
int			my_exit(int err_num);
int			stack_init(int *cash, int counter);
void		print_stack(t_stack *stack);

void		swap_a(t_stack **stack_A);
void		swap_b(t_stack **stack_B);
void		swap_both(t_stack **stack_a, t_stack **stack_b);

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

t_stack		*lstnew(int content, char head, int group, int order);
int			len_stack(t_stack *stack);

void		quick_sort(t_stack **stack_A, t_stack **stack_B, t_medians *orders);
int			sorted_stack(t_stack *stack);

int			median_of_median(int *med_5, int len, int index);
int 		median_On(t_stack *stack);
int			median_of_5(int index, t_stack *stack);
int			array_solver(int *array, int index);
int			median_low(t_stack *stack);


#endif
