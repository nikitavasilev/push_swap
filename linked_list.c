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

void print_list(t_list *head)
{
	t_list *current = head;

	while (current != NULL)
	{
		printf("%d\n", current->num);
		current = current->next;
	}
}

int	main(void)
{
	t_list	*list;
	t_pos	*pos;
	size_t	i;

	list = malloc(sizeof(t_list));
	pos = malloc(sizeof(t_pos));

	list->num = 24;
	pos->head = list;
	list = create_node(list, 42, pos);
	printf("Head: %d\n", pos->head->num);
	printf("Tail: %d\n", pos->tail->num);
	printf("\n\n");
	list = create_node(list, -25, pos);
	list = create_node(list, 32, pos);
	list = create_node(list, INT_MAX, pos);
	list = create_node(list, INT_MIN, pos);

	list = pos->head;
	i = 0;
	while (list->next)
	{
		printf("Node no %zu: %d\n", i++, list->num);
		list = list->next;
	}
	printf("Node no %zu: %d\n", i++, list->num);
	printf("\n\nHead: %d\n", pos->head->num);
	printf("Tail: %d\n", pos->tail->num);
	del_list(pos->head);
	free(pos);
	return (0);
}
