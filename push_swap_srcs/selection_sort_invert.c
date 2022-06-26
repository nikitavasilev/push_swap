/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_invert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:39:55 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/26 22:40:03 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort_invert(t_pos *stack_a, t_pos *stack_b)
{
	size_t	i;
	int		max;
	t_list	*current;

	current = stack_b->head;
	max = find_max(stack_b);
	i = 0;
	while (current)
	{
		if (current->data == max)
		{
			i = find_shortest_path_b(i, stack_b->size, stack_b);
			pa(stack_b, stack_a);
			if (stack_b->size > 0)
			{
				i = 0;
				max = find_max(stack_b);
				current = stack_b->head;
				continue ;
			}
		}
		current = current->next;
		i++;
	}
}
