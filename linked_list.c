#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_list;

typedef struct s_pos
{
	t_list	*head;
	t_list	*tail;
}	t_pos;

t_list	*create_node(t_list *previous, int num, t_pos *pos)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->num = num;
	list->next = NULL;
	previous->next = list;
	pos->tail = (void *)list;
	return (list);
}

void	del_list(t_list *lst)
{
	t_list	*temp;

	while (lst->next)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
	free(lst);
}

void print_list(t_pos *pos)
{
	t_list	*current;
	size_t	i;

	i = 0;
	current = pos->head;
	while (current != pos->tail)
	{
		printf("Node no %zu: %d\n", i++, current->num);
		current = current->next;
	}
	printf("Node no %zu: %d\n", i++, current->num);
}

t_list	*alloc_lst(void)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return(NULL);
	lst->next = NULL;
	return (lst);
}

t_pos	*alloc_pos(void)
{
	t_pos	*pos;

	pos = malloc(sizeof(t_pos));
	if (!pos)
		return (NULL);
	pos->head = NULL;
	pos->tail = NULL;
	return (pos);
}

void	swap(t_pos *node)
{
	t_list	*temp[3];

	temp[0] = node->head;
	temp[1] = node->head->next;
	temp[2] = node->head->next->next;
	node->head = temp[1];
	node->head->next = temp[0];
	node->head->next->next = temp[2];
}

int	main(void)
{
	t_list	*list;
	t_pos	*pos;

	list = alloc_lst();
	pos = alloc_pos();

	list->num = 24;
	pos->head = list;
	list = create_node(list, 42, pos);
	list = create_node(list, -25, pos);
	list = create_node(list, 32, pos);
	list = create_node(list, INT_MAX, pos);
	list = create_node(list, INT_MIN, pos);

	print_list(pos);
	swap(pos);
	printf("\n\nSwap a:\n");
	print_list(pos);

	del_list(pos->head);
	free(pos);
	return (0);
}
