/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:45:55 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/06 09:41:52 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"

static int	*get_array(t_pos *stack_a)
{
	int		*array;
	t_list	*current;
	int		i;

	i = 0;
	array = (int *)malloc(sizeof(int) * stack_a->size);
	if (!array)
		return (NULL);
	current = stack_a->head;
	while (current)
	{
		array[i] = current->data;
		current = current->next;
		i++;
	}
	return (array);
}

t_chunks	*get_chunks(t_pos *stack_a)
{
	int				*array;
	t_chunks		*chunks;
	unsigned int	i;
	unsigned int	j;

	array = get_array(stack_a);
	if (!array)
		return (0);
	chunks = (t_chunks *)malloc(sizeof(t_chunks));
	if (!chunks)
	{
		free(array);
		return (0);
	}
	chunks->count = stack_a->size / CHUNK_SIZE;
	chunks->data = malloc(sizeof(int) * chunks->count);
	if (!chunks->data)
	{
		free(array);
		free(chunks);
		return (0);
	}
	bubble_sort(array, stack_a->size);
	i = 0;
	j = CHUNK_SIZE;
	while (j < stack_a->size)
	{
		chunks->data[i] = array[j - 1];
		i++;
		j += CHUNK_SIZE;
	}
	free(array);
	return (chunks);
}

int	calc_moves_to_up(size_t index, size_t size)
{
	int	ret;

	ret = 0;
	if (index > size / 2)
	{
		while (index < size)
		{
			index++;
			ret++;
		}
	}
	else
	{
		while (index > 0)
		{
			index--;
			ret++;
		}
	}
	return (ret);
}

int	find_cheapest(t_pos *stack, size_t size, int range)
{
	t_list	*current;
	size_t	i;
	int		temp;
	int		moves;
	int		cheapest;

	i = 0;
	moves = INT_MAX;
	current = stack->head;
	while (current)
	{
		if (current->data <= range)
		{
			temp = calc_moves_to_up(i, size);
			if (temp < moves)
			{
				moves = temp;
				cheapest = current->data;
			}
		}
		current = current->next;
		i++;
	}
	return (cheapest);
}

void	push_chunks_to_b(t_pos *stack_a, t_pos *stack_b, t_chunks *chunks)
{
	t_list	*current;
	size_t	i;
	size_t	j;
	int		cheapest;

	i = 0;
	j = 0;
	current = stack_a->head;
	while (current)
	{
		/*if (current->data > chunks->data[0] && current->data <= chunks->data[1] && j == 0)
		{
			if (!is_sorted(stack_a))
			{
				pb(stack_a, stack_b);
				rb(stack_b);
			}
			i = 0;
			current = stack_a->head;
			continue ;
		}*/
		cheapest = find_cheapest(stack_a, stack_a->size, chunks->data[j]);
		if (j < chunks->count && current->data <= chunks->data[j])
		{
			if (current->data == cheapest)
			{
				i = find_shortest_path(i, stack_a->size, stack_a);
				if (!is_sorted(stack_a))
					pb(stack_a, stack_b);
				i = 0;
				current = stack_a->head;
				continue ;
			}
		}
		if (current == stack_a->tail && j < chunks->count)
		{
			current = stack_a->head;
			i = 0;
			j++;
			continue ;
		}
		current = current->next;
		i++;
	}
}

void	partial_sort(t_pos *stack_a, t_pos *stack_b)
{
	t_chunks	*chunks;

	chunks = get_chunks(stack_a);
	if (!chunks)
		return ;
	push_chunks_to_b(stack_a, stack_b, chunks);
	free(chunks->data);
	free(chunks);
	selection_sort_stop(stack_a, stack_b);
	selection_sort_invert(stack_a, stack_b);
	//print_stacks(stack_a, stack_b);
}
