/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:47:55 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/04 06:03:38 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

static void	push_to_b(t_pos *stack_a, t_pos *stack_b, int median)
{
	t_list	*current;

	current = stack_a->head;
	while (current)
	{
		if (stack_a->size == 1)
			return ;
		if (current->data != median)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		current = stack_a->head;
	}
}

static t_pos	*cpy_stack(t_pos *src_stack)
{
	t_pos	*new_stack;
	t_list	*new_stack_lst;
	t_list	*current;

	if (!src_stack->head)
		return (NULL);
	new_stack = alloc_pos();
	new_stack_lst = malloc(sizeof(t_list));
	if (!new_stack_lst)
		return (NULL);
	new_stack_lst->data = src_stack->head->data;
	new_stack_lst->next = NULL;
	new_stack_lst->prev = NULL;
	new_stack->head = new_stack_lst;
	new_stack->tail = new_stack_lst;
	new_stack->size = 1;
	current = src_stack->head->next;
	while (current)
	{
		new_stack_lst = create_node(new_stack_lst, current->data, new_stack);
		current = current->next;
	}
	return (new_stack);
}

static int	calc_moves(t_pos *stack_a, t_pos *stack_b, int median)
{
	t_pos	*new_stack_a;
	t_pos	*new_stack_b;

	(void)median;
	new_stack_a = cpy_stack(stack_a);
	new_stack_b = cpy_stack(stack_b);
	print_stacks(new_stack_a, new_stack_b);
	printf("\n\n");
	return (0);
}

void	insertion_sort(t_pos *stack_a, t_pos *stack_b, int median)
{
	t_list	*current;

	calc_moves(stack_a, stack_b, median);
	printf("median = %d\n", median);
	push_to_b(stack_a, stack_b, median);
	current = stack_b->head;
	print_stacks(stack_a, stack_b);
}
