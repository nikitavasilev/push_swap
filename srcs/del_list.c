/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:57:41 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/16 18:58:48 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	del_list(t_list *lst)
{
	t_list	*temp;

	while (lst->next)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
	free(lst);
}
