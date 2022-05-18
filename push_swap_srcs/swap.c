/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:53:46 by nvasilev          #+#    #+#             */
/*   Updated: 2022/04/12 19:04:52 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

static void	swap(t_pos *node)
{
	t_list	*temp[3];

	temp[0] = node->head;
	temp[1] = node->head->next;
	temp[2] = node->head->next->next;
	node->head = temp[1];
	node->head->next = temp[0];
	node->head->next->next = temp[2];
	node->head->prev = NULL;
	node->head->next->prev = node->head;
	if (node->head->next->next)
		node->head->next->next->prev = node->head->next;
}
/*
static void	swap(t_pos *node)
{
	t_list	*old_next;

	old_next = node->head->next;
	old_next->next = node->head;
	old_next->prev = NULL;
	node->head->next = node->head->next->next;
	node->head = old_next;
	node->head->next->prev = node->head;
}*/

void	sa(t_pos *stack_a)
{
	if (stack_a->size > 1)
		swap(stack_a);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_pos *stack_b)
{
	if (stack_b->size > 1)
		swap(stack_b);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ss(t_pos *stack_a, t_pos *stack_b)
{
	if (stack_a->size > 1 && stack_b->size > 1)
	{
		swap(stack_a);
		swap(stack_b);
	}
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}
