/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:45:55 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/27 01:50:47 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	how_many_elements(t_pos *stack, int range)
{
	t_list	*current;
	int		count;

	count = 0;
	current = stack->head;
	while (current)
	{
		if (current->data <= range)
			count++;
		current = current->next;
	}
	return (count);
}

// static void	p_curr_chk(t_pos *st_a, int *el, t_chunks *chunks, size_t *i)
// {
// 	(*el)--;
// 	if (*el == 0)
// 	{
// 		(*i)++;
// 		*el = how_many_elements(st_a, chunks->data[*i]);
// 	}
// }

// static void	p_nxt_chk(t_pos *st_a, t_pos *st_b, t_list **curr, int next_data)
// {
// 	(*curr) = (*curr)->next;
// 	pb(st_a, st_b);
// 	if ((*curr)->data > next_data)
// 		rr(st_a, st_b);
// 	else
// 		rb(st_b);
// 	(*curr) = st_a->head;
// }

// static int	rotate_or_break(t_pos *stack_a, t_list **curr, int el_to_push)
// {
// 	if (stack_a->size > 1 && el_to_push)
// 	{
// 		ra(stack_a);
// 		(*curr) = stack_a->head;
// 	}
// 	if (!el_to_push)
// 		return (0);
// 	return (1);
// }

// void	push_chunks_to_b(t_pos *stack_a, t_pos *stack_b, t_chunks *chunks)
// {
// 	size_t	i;
// 	t_list	*current;
// 	int		el_to_push;

// 	i = 0;
// 	current = stack_a->head;
// 	el_to_push = how_many_elements(stack_a, chunks->data[i]);
// 	while (current)
// 	{
// 		if (i < chunks->count && current->data <= chunks->data[i])
// 		{
// 			pb(stack_a, stack_b);
// 			p_curr_chk(stack_a, &el_to_push, chunks, &i);
// 			current = stack_a->head;
// 			continue ;
// 		}
// 		if (i + 1 < chunks->count && current->data > chunks->data[i]
// 			&& current->data <= chunks->data[i + 1])
// 		{
// 			p_nxt_chk(stack_a, stack_b, &current, chunks->data[i + 1]);
// 			continue ;
// 		}
// 		if (!rotate_or_break(stack_a, &current, el_to_push))
// 			break ;
// 	}
// }

void	push_chunks_to_b(t_pos *stack_a, t_pos *stack_b, t_chunks *chunks)
{
	size_t	j;
	t_list	*current;
	int		el_to_push;

	j = 0;
	el_to_push = how_many_elements(stack_a, chunks->data[j]);
	current = stack_a->head;
	while (current)
	{
		if (j < chunks->count && current->data <= chunks->data[j])
		{
			pb(stack_a, stack_b);
			current = stack_a->head;
			el_to_push--;
			if (el_to_push == 0)
			{
				j++;
				el_to_push = how_many_elements(stack_a, chunks->data[j]);
			}
			continue ;
		}
		if (j + 1 < chunks->count && current->data > chunks->data[j]
			&& current->data <= chunks->data[j + 1])
		{
			current = current->next;
			pb(stack_a, stack_b);
			if (current->data > chunks->data[j + 1])
				rr(stack_a, stack_b);
			else
				rb(stack_b);
			current = stack_a->head;
			continue ;
		}
		if (current == stack_a->tail && j < chunks->count)
		{
			current = stack_a->head;
			continue ;
		}
		if (stack_a->size > 1 && el_to_push)
		{
			ra(stack_a);
			current = stack_a->head;
		}
		if (!el_to_push && j + 1 < chunks->count)
		{
			j++;
			el_to_push = how_many_elements(stack_a, chunks->data[j]);
		}
		if (!el_to_push)
			break ;
	}
}
