/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:31:36 by nvasilev          #+#    #+#             */
/*   Updated: 2022/05/27 02:34:17 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

t_values	*find_median(t_pos *stack_a)
{
	int			*array;
	t_values	*a_values;

	array = get_array(stack_a);
	if (!array)
		return (0);
	a_values = (t_values *)malloc(sizeof(t_values));
	if (!a_values)
	{
		free(array);
		return (0);
	}
	bubble_sort(array, stack_a->size);
	a_values->median = array[stack_a->size / 2];
	a_values->min = array[0];
	a_values->max = array[stack_a->size - 1];
	free(array);
	return (a_values);
}
