/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:47:55 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/31 06:27:30 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_list	*alloc_lst(void)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

t_pos	*alloc_pos(void)
{
	t_pos	*pos;

	pos = malloc(sizeof(t_pos));
	if (!pos)
		return (NULL);
	pos->head = NULL;
	pos->tail = NULL;
	pos->size = 0;
	return (pos);
}
