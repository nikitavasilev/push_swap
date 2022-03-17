#include <stdio.h>
#include <limits.h>

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (c);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

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

int	main(int argc, char const *argv[])
{
	int	error;
	int	res;

	if (argc == 2)
	{
		error = 0;
		res = atoi_err_overflow(argv[1], &error);
		if (error)
		{
			printf("Error\n");
			return (1);
		}
		printf("Success: %i\n", res);
	}
	else
		printf("Usage: ./push_swap <integers>\n");
	return (0);
}
