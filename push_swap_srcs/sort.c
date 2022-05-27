/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:02:52 by nvasilev          #+#    #+#             */
/*   Updated: 2022/04/13 23:05:36 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static int	find_min(t_pos *stack_a)
{
	t_list	*current;
	int		min;

	current = stack_a->head;
	min = current->data;
	while (current)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
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

static int	is_rev_sorted(t_pos *stack)
{
	t_list	*lst;

	lst = stack->head;
	while (lst->next)
	{
		if (lst->data < lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static size_t	find_shortest_path(size_t index, size_t size, t_pos *stack)
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

static int	smart_swap_a(t_pos *stack_a)
{
	if (stack_a->size == 2)
	{
		if (stack_a->head->data > stack_a->head->next->data)
		{
			sa(stack_a);
			return (1);
		}
	}
	else if (stack_a->size >= 3)
	{
		if (stack_a->head->next->next->data > stack_a->head->data &&
			stack_a->head->next->next->data > stack_a->head->next->data)
		{
			sa(stack_a);
			return (1);
		}
	}
	return (0);
}

static void	selection_sort(t_pos *stack_a, t_pos *stack_b)
{
	size_t	i;
	int		min;
	t_list	*current;

	current = stack_a->head;
	min = find_min(stack_a);
	i = 0;
	while (current)
	{
		if (stack_a->size == 3 && is_rev_sorted(stack_a))
		{
			ra(stack_a);
			sa(stack_a);
			continue ;
		}
		if (i == 0 && stack_a->size >= 3 && !is_sorted(stack_a))
		{
			if (smart_swap_a(stack_a))
				current = stack_a->head;
		}
		if (current->data == min)
		{
			i = find_shortest_path(i, stack_a->size, stack_a);
			if (!is_sorted(stack_a))
				pb(stack_a, stack_b);
			if (stack_a->size > 1 && !is_sorted(stack_a))
			{
				i = 0;
				min = find_min(stack_a);
				current = stack_a->head;
				continue ;
			}
		}
		current = current->next;
		i++;
	}
	if (stack_b->size > 0)
		while (stack_b->head)
			pa(stack_b, stack_a);
}

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

static int	bubble_sort(int *array, unsigned int size)
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

int	sort(t_pos *stack_a, t_pos *stack_b)
{
	t_values	*a_values;

	a_values = find_median(stack_a);
	if (!a_values)
		return (0);
//	printf("median: %d\n", a_values->median);
	(void)stack_b;
	if (is_sorted(stack_a))
	{
		free(a_values);
		return (1);
	}
	if (stack_a->size <= 500)
		selection_sort(stack_a, stack_b);
/*	else
		quicksort(stack_a, stack_b);*/
	free(a_values);
	return (1);
}