/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:55:03 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/28 23:17:07 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_list	*create_node(t_list *previous, int num, t_pos *pos)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->num = num;
	list->next = NULL;
	list->previous = previous;
	previous->next = list;
	pos->tail = list;
	pos->size++;
	return (list);
}
