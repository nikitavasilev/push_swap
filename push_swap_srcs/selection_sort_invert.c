/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_invert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:39:55 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/27 12:34:14 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_second_max(t_pos *stack, int max)
{
	t_list	*current;
	int		second_max;

	current = stack->head;
	second_max = current->data;
	while (current)
	{
		if (current->data > second_max && current->data < max)
			second_max = current->data;
		current = current->next;
	}
	return (second_max);
}

size_t	smart_push_to_a(size_t index, size_t size, t_pos *stack_a, t_pos *stack_b, int second_max)
{
	if (index > size / 2)
	{
		while (index < size)
		{
			rrb(stack_b);
			if (stack_b->head->data == second_max)
				pa(stack_b, stack_a);
			index++;
		}
	}
	else
	{
		while (index > 0)
		{
			rb(stack_b);
			if (stack_b->head->data == second_max)
			{
				pa(stack_b, stack_a);
				index--;
			}
			index--;
		}
	}
	return (index);
}

void	selection_sort_invert(t_pos *stack_a, t_pos *stack_b)
{
	size_t	i;
	int		max;
	int		second_max;
	t_list	*current;

	current = stack_b->head;
	max = find_max(stack_b);
	second_max = find_second_max(stack_b, max);
	i = 0;
	while (current)
	{
		if (current->data == max)
		{
			i = smart_push_to_a(i, stack_b->size, stack_a, stack_b, second_max);
			pa(stack_b, stack_a);
			if (stack_b->size > 0)
			{
				i = 0;
				max = find_max(stack_b);
				second_max = find_second_max(stack_b, max);
				if (stack_a->head->data > stack_a->head->next->data)
					sa(stack_a);
				current = stack_b->head;
				continue ;
			}
		}
		current = current->next;
		i++;
	}
}
