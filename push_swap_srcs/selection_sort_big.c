/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_big.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:35:44 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/26 23:36:17 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_pos *stack_a, t_pos *stack_b)
{
	if (stack_a->size > 0)
		while (stack_a->head)
			pb(stack_a, stack_b);
}

static void	push_min_to_b(t_pos *st_a, t_pos *st_b, size_t *index, int *min)
{
	*index = find_shortest_path(*index, st_a->size, st_a);
	if (!is_sorted(st_a))
		pb(st_a, st_b);
	if (st_a->size > 1 && !is_sorted(st_a))
	{
		*index = 0;
		*min = find_min(st_a);
	}
}

static void	push_max_to_b(t_pos *st_a, t_pos *st_b, size_t *index, int *max)
{
	*index = find_shortest_path(*index, st_a->size, st_a);
	if (!is_sorted(st_a))
	{
		pb(st_a, st_b);
		rb(st_b);
	}
	if (st_a->size > 0)
	{
		*index = 0;
		*max = find_max(st_a);
	}
}

static int	init_loop(t_pos *stack_a, t_list **current, int *min, int *max)
{
	*current = stack_a->head;
	*min = find_min(stack_a);
	*max = find_max(stack_a);
	return (0);
}

void	selection_sort_stop_min_max(t_pos *stack_a, t_pos *stack_b)
{
	size_t	i;
	int		min;
	int		max;
	t_list	*current;

	i = init_loop(stack_a, &current, &min, &max);
	while (current)
	{
		if (current->data == min || current->data == max)
		{
			if (current->data == min)
				push_min_to_b(stack_a, stack_b, &i, &min);
			else
				push_max_to_b(stack_a, stack_b, &i, &max);
			if (stack_a->size > 0 && !is_sorted(stack_a))
			{
				i = 0;
				current = stack_a->head;
				continue ;
			}
		}
		current = current->next;
		i++;
	}
	push_to_b(stack_a, stack_b);
}
