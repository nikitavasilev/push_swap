/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:45:40 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/25 00:42:37 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

static void	push(t_pos *src, t_pos *dest)
{
	t_list	*temp[2];

	temp[1] = NULL;
	temp[0] = src->head->next;
	if (dest->head)
		temp[1] = dest->head;
	dest->head = src->head;
	dest->head->next = temp[1];
	if (!temp[1])
		dest->head->previous = NULL;
	src->head = temp[0];
	src->head->previous = NULL;
}

void	pa(t_pos *stack_b, t_pos *stack_a)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_pos *stack_a, t_pos *stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}