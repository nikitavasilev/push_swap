/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:53:46 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/24 20:00:42 by nvasilev         ###   ########.fr       */
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
}

void	sa(t_pos *stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_pos *stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ss(t_pos *stack_a, t_pos *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}
