/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:02:52 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/27 21:05:36 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	partial_sort(t_pos *stack_a, t_pos *stack_b)
{
	t_chunks	*chunks;
	t_stacks	stacks;

	stacks.a = stack_a;
	stacks.b = stack_b;
	chunks = get_chunks(stack_a);
	if (!chunks)
		return ;
	push_chunks_to_b(stack_a, stack_b, chunks);
	free(chunks->data);
	free(chunks);
	if (stack_a->size <= 20)
		selection_sort_stop(stack_a, stack_b);
	else
		selection_sort_stop_min_max(stack_a, stack_b);
	selection_sort_invert(stack_a, stack_b, &stacks);
}

int	sort(t_pos *stack_a, t_pos *stack_b)
{
	if (is_sorted(stack_a))
		return (1);
	if (stack_a->size <= 20)
		selection_sort_small(stack_a, stack_b);
	else
		partial_sort(stack_a, stack_b);
	if (is_sorted(stack_a))
		return (1);
	return (0);
}
