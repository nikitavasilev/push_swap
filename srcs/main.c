/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:25:43 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/09 01:50:31 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		if (check_args(argc, argv))
			printf("yes\n");
	}
	else
		ft_error("Usage: ./push_swap <integers>");
	return (0);
}
