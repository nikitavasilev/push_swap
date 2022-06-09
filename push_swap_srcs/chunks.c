/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:45:55 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/07 09:49:50 by nvasilev         ###   ########.fr       */
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

float	power(float x, int y)
{
	float	res;

	res = 1;
	while (y)
	{
		res *= x;
		y--;
	}
	return (res);
}

t_chunks	*get_chunks(t_pos *stack_a)
{
	int				*array;
	t_chunks		*chunks;
	unsigned int	i;
	unsigned int	j;
	unsigned int	chunk_size;

	if (stack_a->size > 100)
		chunk_size = 20 * power(1.2, stack_a->size / 100) + 1;
	else
		chunk_size = stack_a->size * 0.2;
	array = get_array(stack_a);
	if (!array)
		return (0);
	chunks = (t_chunks *)malloc(sizeof(t_chunks));
	if (!chunks)
	{
		free(array);
		return (0);
	}
	chunks->count = stack_a->size / chunk_size;
	chunks->data = malloc(sizeof(int) * chunks->count);
	if (!chunks->data)
	{
		free(array);
		free(chunks);
		return (0);
	}
	bubble_sort(array, stack_a->size);
	i = 0;
	j = chunk_size;
	while (i < chunks->count)
	{
		chunks->data[i] = array[j - 1];
		i++;
		j += chunk_size - (chunk_size * 0.1);
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

int	steps_to_tail(t_pos *stack, int range)
{
	t_list	*current;
	int		steps;

	steps = 0;
	current = stack->head;
	while (current)
	{
		if (current->data <= range)
			return (steps);
		current = current->next;
		steps++;
	}
	return (steps);
}

int	steps_to_head(t_pos *stack, int range)
{
	t_list	*current;
	int		steps;

	steps = 0;
	current = stack->tail;
	while (current)
	{
		if (current->data <= range)
			return (steps);
		current = current->prev;
		steps++;
	}
	return (steps);
}

void	push_chunks_to_b(t_pos *stack_a, t_pos *stack_b, t_chunks *chunks)
{
	t_list	*current;
	size_t	i;
	size_t	j;
	int		up;

	i = 0;
	j = 0;
	current = stack_a->head;
	if (steps_to_head(stack_a, chunks->data[j]) <
		steps_to_tail(stack_a, chunks->data[j]))
		up = 1;
	else
		up = 0;
	while (current)
	{
		if (j + 1 < chunks->count && i == 0)
		{
			if (current->data > chunks->data[j] && current->data <= chunks->data[j + 1])
			{
				pb(stack_a, stack_b);
				rb(stack_b);
				i = 0;
				current = stack_a->head;
				continue ;
			}
		}
		if (j < chunks->count && current->data <= chunks->data[j])
		{
			if (!up)
			{
				while (i > 0)
				{
					ra(stack_a);
					current = stack_a->head;
					if (j + 1 < chunks->count)
					{
						if (current->data > chunks->data[j] && current->data <= chunks->data[j + 1])
						{
							pb(stack_a, stack_b);
							rb(stack_b);
							i = 0;
							current = stack_a->head;
							break ;
						}
					}
					i--;
				}
			}
			else if (up)
			{
				while (i < stack_a->size)
				{
					rra(stack_a);
					current = stack_a->head;
					if (j + 1 < chunks->count)
					{
						if (current->data > chunks->data[j] && current->data <= chunks->data[j + 1])
						{
							pb(stack_a, stack_b);
							rb(stack_b);
							i = 0;
							current = stack_a->head;
							break ;
						}
					}
					i++;
				}
			}
			if (j < chunks->count && current->data <= chunks->data[j])
				pb(stack_a, stack_b);
			i = 0;
			current = stack_a->head;
			continue ;
		}
		if (current == stack_a->tail && j < chunks->count)
		{
			current = stack_a->head;
			i = 0;
			j++;
			if (steps_to_head(stack_a, chunks->data[j]) <
				steps_to_tail(stack_a, chunks->data[j]))
				up = 1;
			else
				up = 0;
			continue ;
		}
		current = current->next;
		i++;
	}
}

// void	push_chunks_to_b(t_pos *stack_a, t_pos *stack_b, t_chunks *chunks)
// {
// 	t_list	*current;
// 	size_t	i;
// 	size_t	j;
// 	int		cheapest;

// 	i = 0;
// 	j = 0;
// 	current = stack_a->head;
// 	while (current)
// 	{
// 		if (j + 1 < chunks->count && i == 0)
// 		{
// 			if (current->data > chunks->data[j] && current->data <= chunks->data[j + 1])
// 			{
// 				pb(stack_a, stack_b);
// 				rb(stack_b);
// 				i = 0;
// 				current = stack_a->head;
// 				continue ;
// 			}
// 		}
// 		if (j < chunks->count && current->data <= chunks->data[j])
// 		{
// 			cheapest = find_cheapest(stack_a, stack_a->size, chunks->data[j]);
// 			if (current->data == cheapest)
// 			{
// 				i = find_shortest_path(i, stack_a->size, stack_a);
// 				if (!is_sorted(stack_a))
// 					pb(stack_a, stack_b);
// 				i = 0;
// 				current = stack_a->head;
// 				continue ;
// 			}
// 		}
// 		if (current == stack_a->tail && j < chunks->count)
// 		{
// 			current = stack_a->head;
// 			i = 0;
// 			j++;
// 			continue ;
// 		}
// 		current = current->next;
// 		i++;
// 	}
// }

void	partial_sort(t_pos *stack_a, t_pos *stack_b)
{
	t_chunks	*chunks;

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
	selection_sort_invert(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
}
