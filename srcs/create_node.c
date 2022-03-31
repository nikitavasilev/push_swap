/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:55:03 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/31 06:28:17 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_list	*create_node(t_list *prev, int data, t_pos *pos)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->data = data;
	list->next = NULL;
	list->prev = prev;
	prev->next = list;
	pos->tail = list;
	pos->size++;
	return (list);
}
