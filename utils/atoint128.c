/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoint128.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:55:02 by nvasilev          #+#    #+#             */
/*   Updated: 2022/01/09 16:55:29 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

__int128_t	atoint128(const char *str)
{
	__int128_t	nb;
	char		sign;

	while ((ft_isspace(*str)))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	nb = 0;
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * sign);
}
