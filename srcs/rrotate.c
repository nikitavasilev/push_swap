/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:59:09 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/16 19:59:34 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	rrotate(t_pos *node)
{
	t_list	*temp;

	temp = node->tail->previous;
	node->tail->next = node->head;
	node->tail->previous->next = NULL;
	node->head = node->tail;
	node->head->previous = NULL;
	node->tail = temp;
}
