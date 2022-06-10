/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:46:52 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/10 03:27:25 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_shortest_path_and_push_next_chunk(size_t index, size_t size, t_pos *stack_a, t_pos *stack_b, t_chunks *chunks, size_t j_index)
{
	if (index > size / 2)
	{
		while (index < size)
		{
			rra(stack_a);
			index++;
			if (stack_a->head->data > chunks->data[j_index] && stack_a->head->data <= chunks->data[j_index + 1])
			{
				pb(stack_a, stack_b);
				rb(stack_b);
			}
		}
	}
	else
	{
		while (index > 0)
		{
			ra(stack_a);
			index--;
			if (stack_a->head->data > chunks->data[j_index] && stack_a->head->data <= chunks->data[j_index + 1])
			{
				pb(stack_a, stack_b);
				index--;
				if (index > 1)
				{
					rr(stack_a, stack_b);
					index--;
				}
				else
					rb(stack_b);
			}
		}
	}
	return (index);
}

size_t	find_shortest_path(size_t index, size_t size, t_pos *stack)
{
	if (index > size / 2)
	{
		while (index < size)
		{
			rra(stack);
			index++;
		}
	}
	else
	{
		while (index > 0)
		{
			ra(stack);
			index--;
		}
	}
	return (index);
}

size_t	find_shortest_path_b(size_t index, size_t size, t_pos *stack)
{
	if (index > size / 2)
	{
		while (index < size)
		{
			rrb(stack);
			index++;
		}
	}
	else
	{
		while (index > 0)
		{
			rb(stack);
			index--;
		}
	}
	return (index);
}
