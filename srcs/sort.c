/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:02:52 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/31 10:22:14 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_sort(t_pos *stack_a, t_pos *stack_b)
{
	t_list	*current;

	current = stack_a->head;
	while (current->next)
	{
		if (current->data > current->next->data)
		{
			if (stack_b->size == 0)
				push_a(stack_a, stack_b);
			else
				rotate_a(stack_a, stack_b);
		}
		else
			current = current->next;
	}
}

static int	is_sorted(t_pos *stack)
{
	t_list	*lst;

	lst = stack->head;
	while (lst->next)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort(t_pos *stack_a, t_pos *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size <= 10)
		insertion_sort(stack_a, stack_b);
	else
		quicksort(stack_a, stack_b);
}
