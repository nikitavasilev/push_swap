/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:47:38 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/27 11:14:54 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

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

static unsigned int	calc_chunks_size(t_pos *stack_a)
{
	unsigned int	chunk_size;

	if (stack_a->size > 100)
		chunk_size = 18 * power(1.075, stack_a->size / 100) + 1;
	else
		chunk_size = stack_a->size * 0.1;
	return (chunk_size);
}

static t_chunks	*init_chunks(t_chunks *chunks, t_pos *stack_a, size_t *ch_size)
{
	*ch_size = calc_chunks_size(stack_a);
	chunks = (t_chunks *)malloc(sizeof(t_chunks));
	if (!chunks)
		return (0);
	chunks->count = 0;
	chunks->count = stack_a->size / *ch_size;
	chunks->data = malloc(sizeof(int) * chunks->count);
	if (!chunks->data)
	{
		free(chunks);
		return (NULL);
	}
	return (chunks);
}

t_chunks	*get_chunks(t_pos *stack_a)
{
	int			*array;
	t_chunks	*chunks;
	size_t		i;
	size_t		j;
	size_t		chunk_size;

	chunks = NULL;
	chunk_size = 0;
	chunks = init_chunks(chunks, stack_a, &chunk_size);
	if (!chunks)
		return (0);
	array = get_array(stack_a);
	if (!array)
		return (0);
	bubble_sort(array, stack_a->size);
	i = 0;
	j = chunk_size;
	while (i < chunks->count)
	{
		chunks->data[i] = array[j - 1];
		i++;
		j += chunk_size - (chunk_size * 0.025);
	}
	free(array);
	return (chunks);
}
