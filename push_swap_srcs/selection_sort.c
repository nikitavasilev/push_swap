/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:35:44 by nvasilev          #+#    #+#             */
/*   Updated: 2022/05/27 02:36:30 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_pos *stack_a, t_pos *stack_b)
{
	size_t	i;
	int		min;
	t_list	*current;

	current = stack_a->head;
	min = find_min(stack_a);
	i = 0;
	while (current)
	{
		if (stack_a->size == 3 && is_rev_sorted(stack_a))
		{
			ra(stack_a);
			sa(stack_a);
			continue ;
		}
		if (i == 0 && stack_a->size >= 3 && !is_sorted(stack_a))
		{
			if (smart_swap_a(stack_a))
				current = stack_a->head;
		}
		if (current->data == min)
		{
			i = find_shortest_path(i, stack_a->size, stack_a);
			if (!is_sorted(stack_a))
				pb(stack_a, stack_b);
			if (stack_a->size > 1 && !is_sorted(stack_a))
			{
				i = 0;
				min = find_min(stack_a);
				current = stack_a->head;
				continue ;
			}
		}
		current = current->next;
		i++;
	}
	if (stack_b->size > 0)
		while (stack_b->head)
			pa(stack_b, stack_a);
}
