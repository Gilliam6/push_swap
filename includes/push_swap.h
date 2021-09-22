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

#endif
