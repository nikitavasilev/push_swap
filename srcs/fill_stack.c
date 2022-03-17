/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:49:14 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/17 07:51:33 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static void	free_2d(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static int	check_args(char *str, int *err)
{
	int	num;

	num = atoi_err_overflow(str, err);
	if (*err)
		return (1);
	return (num);
}

t_pos	*fill_stack(char **args)
{
	size_t	i;
	t_list	*list;
	t_pos	*pos;
	int		num;
	int		err;

	err = 0;
	list = alloc_lst();
	pos = alloc_pos();
	list->num = check_args(args[0], &err);
	list->previous = NULL;
	pos->head = list;
	i = 1;
	while (args[i])
	{
		num = check_args(args[i], &err);
		list = create_node(list, num, pos);
		i++;
	}
	free_2d(args);
	if (err)
	{
		del_list(pos->head);
		free(pos);
		ft_error("Error");
	}
	return (pos);
}
