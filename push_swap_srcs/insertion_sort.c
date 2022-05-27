/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:47:55 by nvasilev          #+#    #+#             */
/*   Updated: 2022/05/27 02:50:57 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_pos *stack_a, t_pos *stack_b, int median)
{
	t_list	*current;

	current = stack_a->head;
	while (current)
	{
		if (current->data != median)
			pb(stack_a, stack_b);
		current = current->next;
	}
}

void	insertion_sort(t_pos *stack_a, t_pos *stack_b, int median)
{
	t_list	*current;

	push_to_b(stack_a, stack_b, median);
	current = stack_b->head;

}
