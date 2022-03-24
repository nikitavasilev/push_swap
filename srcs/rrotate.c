/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:59:09 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/24 19:57:44 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

static void	rrotate(t_pos *node)
{
	t_list	*temp;

	temp = node->tail->previous;
	node->tail->next = node->head;
	node->tail->previous->next = NULL;
	node->head = node->tail;
	node->head->previous = NULL;
	node->tail = temp;
}

void	rra(t_pos *stack_a)
{
	rrotate(stack_a);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_pos *stack_b)
{
	rrotate(stack_b);
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_pos *stack_a, t_pos *stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}

