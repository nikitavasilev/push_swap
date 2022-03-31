/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 06:44:06 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/31 06:21:18 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

char	**parse(const char **argv)
{
	size_t	i;
	char	*str;
	char	**args;

	str = ft_strdup("");
	i = 1;
	while (argv[i])
	{
		if (!ft_strlen(argv[i]))
		{
			free(str);
			ft_error("Error");
		}
		str = strjoin_free_s1(str, argv[i]);
		if (argv[i + 1])
			str = strjoin_free_s1(str, " ");
		i++;
	}
	args = ft_split(str, ' ');
	free(str);
	return (args);
}
