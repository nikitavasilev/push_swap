/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:45:55 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/28 01:21:55 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	how_many_elements(t_pos *stack, int range)
{
	t_list	*current;
	int		count;

	count = 0;
	current = stack->head;
	while (current)
	{
		if (current->data <= range)
			count++;
		current = current->next;
	}
	return (count);
}

static void	push_next_chunk(t_pos *stack_a, t_pos *stack_b, int nxt_chunk_limit)
{
	pb(stack_a, stack_b);
	if (stack_a->head->data > nxt_chunk_limit)
		rr(stack_a, stack_b);
	else
		rb(stack_b);
}

void	push_chunks_to_b(t_pos *stack_a, t_pos *stack_b, t_chunks *chunks)
{
	size_t	j;
	int		el_to_push;

	j = 0;
	el_to_push = how_many_elements(stack_a, chunks->data[j]);
	while (stack_a->head && !(j == chunks->count - 1 && !el_to_push))
	{
		if (j < chunks->count && stack_a->head->data <= chunks->data[j])
		{
			pb(stack_a, stack_b);
			if (--el_to_push == 0 && j + 1 < chunks->count)
				el_to_push = how_many_elements(stack_a, chunks->data[++j]);
		}
		else if (j + 1 < chunks->count && stack_a->head->data > chunks->data[j]
			&& stack_a->head->data <= chunks->data[j + 1])
			push_next_chunk(stack_a, stack_b, chunks->data[j + 1]);
		else if (stack_a->size > 1 && el_to_push)
			ra(stack_a);
		else
			el_to_push = how_many_elements(stack_a, chunks->data[++j]);
	}
}
