/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:56:56 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/16 19:58:07 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	rotate(t_pos *node)
{
	t_list	*temp[2];

	temp[0] = node->head->next;
	temp[1] = node->tail;
	node->tail->next = node->head;
	node->tail = node->head;
	node->tail->next = NULL;
	node->tail->previous = temp[1];
	node->head = temp[0];
	node->head->previous = NULL;
}
