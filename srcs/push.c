/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:45:40 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/22 12:12:31 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	push(t_pos *src, t_pos *dest)
{
	t_list	*temp[2];

	temp[0] = src->head->next;
	if (dest->head)
		temp[1] = dest->head->next;
	dest->head = src->head;
	dest->head->next = temp[1];
	dest->head->previous = NULL;
	src->head = temp[0];
	src->head->previous = NULL;
}
