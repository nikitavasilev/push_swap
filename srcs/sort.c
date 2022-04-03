/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:02:52 by nvasilev          #+#    #+#             */
/*   Updated: 2022/04/03 21:08:53 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

/*static void	insertion_sort(t_pos *stack_a, t_pos *stack_b)
{
	t_list	*current;

	current = stack_a->head;
	while (current->next)
	{
		if (current->data > current->next->data)
		{
			if (stack_b->size == 0)
				push_a(stack_a, stack_b);
			else
				rotate_a(stack_a, stack_b);
		}
		else
			current = current->next;
	}
}*/

static int	*get_array(t_pos *stack_a)
{
	int		*array;
	t_list	*current;
	int		i;

	i = 0;
	array = (int*)malloc(sizeof(int) * stack_a->size);
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

static int bubble_sort(int *array, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	find_median(t_pos *stack_a)
{
	int		*array;
	int		median;

	array = get_array(stack_a);
	bubble_sort(array, stack_a->size);
	median = array[stack_a->size / 2];
	free(array);
	return (median);
}

static int	is_sorted(t_pos *stack)
{
	t_list	*lst;

	lst = stack->head;
	while (lst->next)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort(t_pos *stack_a, t_pos *stack_b)
{
	int	median;

	median = find_median(stack_a);
	printf("median: %d\n", median);
	(void)stack_b;
	if (is_sorted(stack_a))
		return ;
/*	if (stack_a->size <= 10)
		insertion_sort(stack_a, stack_b);
	else
		quicksort(stack_a, stack_b);*/
}
