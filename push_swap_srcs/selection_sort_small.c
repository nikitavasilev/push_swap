/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:13:54 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/27 01:51:40 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	push_min_to_b(t_pos *st_a, t_pos *st_b, size_t *index, int *min)
// {
// 	*index = find_shortest_path(*index, st_a->size, st_a);
// 	if (!is_sorted(st_a))
// 		pb(st_a, st_b);
// 	if (st_a->size > 1 && !is_sorted(st_a))
// 	{
// 		*index = 0;
// 		*min = find_min(st_a);
// 	}
// }

// static void	push_back_to_a(t_pos *stack_a, t_pos *stack_b)
// {
// 	if (stack_b->size > 0)
// 		while (stack_b->head)
// 			pa(stack_b, stack_a);
// }

// static void	check_swap_optimizer(t_pos *stack_a, t_list **current)
// {
// 	if (stack_a->size == 3 && is_rev_sorted(stack_a))
// 	{
// 		ra(stack_a);
// 		sa(stack_a);
// 		*current = stack_a->head;
// 	}
// 	else if (stack_a->size >= 3 && !is_sorted(stack_a))
// 		if (smart_swap_a(stack_a))
// 			*current = stack_a->head;
// }

// void	selection_sort_small(t_pos *stack_a, t_pos *stack_b)
// {
// 	size_t	i;
// 	int		min;
// 	t_list	*current;

// 	current = stack_a->head;
// 	min = find_min(stack_a);
// 	i = 0;
// 	while (current)
// 	{
// 		check_swap_optimizer(stack_a, &current);
// 		if (current->data == min)
// 		{
// 			push_min_to_b(stack_a, stack_b, &i, &min);
// 			if (stack_a->size > 1 && !is_sorted(stack_a))
// 			{
// 				current = stack_a->head;
// 				continue ;
// 			}
// 		}
// 		current = current->next;
// 		i++;
// 	}
// 	push_back_to_a(stack_a, stack_b);
// }

void	selection_sort_small(t_pos *stack_a, t_pos *stack_b)
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
