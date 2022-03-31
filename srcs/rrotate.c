/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:59:09 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/31 03:27:44 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

static void	rrotate(t_pos *node)
{
	t_list	*old_head;
	t_list	*old_tail;

	old_head = node->head;
	old_tail = node->tail;
	node->tail = old_tail->previous;
	node->head = old_tail;
	node->tail->next = NULL;
	node->head->next = old_head;
	node->head->previous = NULL;
	old_head->previous = node->head;
}

void	rra(t_pos *stack_a)
{
	if (stack_a->size > 1)
		rrotate(stack_a);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_pos *stack_b)
{
	if (stack_b->size > 1)
		rrotate(stack_b);
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_pos *stack_a, t_pos *stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
