/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_err_overflow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:35:19 by nvasilev          #+#    #+#             */
/*   Updated: 2022/03/17 06:24:21 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h>

int	atoi_err_overflow(const char *str, int *err)
{
	__int64_t	nb;
	__int64_t	max;
	char		sign;

	max = INT_MAX;
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
		if (((int)nb < 0 && !((int)nb == INT_MIN && sign == -1))
			|| (nb > (max + 1) && sign == -1))
		{
			*err = 1;
			return (1);
		}
		str++;
	}
	if (!ft_isdigit(*str) && *str)
	{
		*err = 1;
		return (1);
	}
	return (nb * sign);
}
