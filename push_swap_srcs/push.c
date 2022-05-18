/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:45:40 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/31 06:30:55 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

static void	push(t_pos *src, t_pos *dest)
{
	t_list	*temp_src_head;
	t_list	*temp_dest_head;

	temp_dest_head = dest->head;
	if (src->head)
	{
		temp_src_head = src->head;
		src->head = src->head->next;
		if (src->head)
			src->head->prev = NULL;
		else
			src->tail = NULL;
	}
	if (dest->head)
	{
		dest->head->prev = temp_src_head;
		temp_src_head->next = dest->head;
		dest->head = temp_src_head;
	}
	else
	{
		dest->head = temp_src_head;
		dest->tail = temp_src_head;
	}
	dest->head->next = temp_dest_head;
}

void	pa(t_pos *stack_b, t_pos *stack_a)
{
	if (stack_b->head)
	{
		push(stack_b, stack_a);
		stack_a->size++;
		stack_b->size--;
	}
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_pos *stack_a, t_pos *stack_b)
{
	if (stack_a->head)
	{
		push(stack_a, stack_b);
		stack_b->size++;
		stack_a->size--;
	}
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}
