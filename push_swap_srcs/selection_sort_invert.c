/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_invert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:39:55 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/27 20:02:10 by nvasilev         ###   ########.fr       */
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

static size_t	smart_pa(size_t index, size_t size, t_stacks *stacks, int s_max)
{
	if (index > size / 2)
	{
		while (index < size)
		{
			rrb(stacks->b);
			if (stacks->b->head->data == s_max)
				pa(stacks->b, stacks->a);
			index++;
		}
	}
	else
	{
		while (index > 0)
		{
			rb(stacks->b);
			if (stacks->b->head->data == s_max)
			{
				pa(stacks->b, stacks->a);
				index--;
			}
			index--;
		}
	}
	return (index);
}

static void	find_new_max(t_stacks *stacks, int *s_max, int *max, t_list **curr)
{
	*max = find_max(stacks->b);
	*s_max = find_second_max(stacks->b, *max);
	if (stacks->a->head->data > stacks->a->head->next->data)
		sa(stacks->a);
	*curr = stacks->b->head;
}

void	selection_sort_invert(t_pos *stack_a, t_pos *stack_b, t_stacks *stacks)
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
			i = smart_pa(i, stack_b->size, stacks, second_max);
			pa(stack_b, stack_a);
			if (stack_b->size > 0)
			{
				i = 0;
				find_new_max(stacks, &second_max, &max, &current);
				continue ;
			}
		}
		current = current->next;
		i++;
	}
}
