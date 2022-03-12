#include <stdio.h>
#include <stdlib.h>

typedef struct s_list		t_list;
typedef struct s_head_tail	t_head_tail;

struct s_list
{
	int		num;
	t_list	*next;
};

struct s_head_tail
{
	t_list	*head;
	t_list	*tail;
};

t_list	*create_node(t_list *previous, int num, t_list **tail)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->num = num;
	previous->next = list;
	*tail = list;
	return (list);
}

int	main(int argc, char const *argv[])
{
	t_list		*list;
	t_head_tail	*head_tail;

	list = malloc(sizeof(t_list));
	head_tail = malloc(sizeof(t_head_tail));

	list->num = 24;
	head_tail->head = list;
	t_list	*new_node;
	create_node(list, 42, &head_tail->tail);
	printf("%d\n", head_tail->tail->num);
	return (0);
}
