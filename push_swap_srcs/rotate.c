/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:56:56 by nvasilev          #+#    #+#             */
/*   Updated: 2022/06/26 20:52:59 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

static void	rotate(t_pos *node)
{
	t_list	*temp[2];

	temp[0] = node->head->next;
	temp[1] = node->tail;
	node->tail->next = node->head;
	node->tail = node->head;
	node->tail->next = NULL;
	node->tail->prev = temp[1];
	node->head = temp[0];
	node->head->prev = NULL;
}

void	ra(t_pos *stack_a)
{
	if (stack_a->size > 1)
		rotate(stack_a);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_pos *stack_b)
{
	if (stack_b->size > 1)
		rotate(stack_b);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_pos *stack_a, t_pos *stack_b)
{
	if (stack_a->size > 1)
		rotate(stack_a);
	if (stack_b->size > 1)
		rotate(stack_b);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
