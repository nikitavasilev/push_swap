/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_stop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:39:24 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/26 22:39:43 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort_stop(t_pos *stack_a, t_pos *stack_b)
{
	size_t	i;
	int		min;
	t_list	*current;

	current = stack_a->head;
	min = find_min(stack_a);
	i = 0;
	while (current)
	{
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
}
