#include <stdio.h>
#include <limits.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

// INT_MAX == 2147483647
// INT_MIN == -2147483648

int	check_int_len(char *str)
{
	int		len;
	size_t	i;

	i = 0;
	len = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		len++;
	}
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		len++;
	}
	if (len > sizeof(int) * 2 + 3)
		return (0);
	return (len);
}

int	main(int argc, char const *argv[])
{
	__int128_t	nb;

	if (argc == 2)
	{
		if (!check_int_len(argv[1]))
			printf("Error\n");
		else
		{
			nb = atoint128(argv[1]);
			if (nb < 0)
			{
				if (nb < INT_MIN)
					printf("Error\n");
			}
			else
			{
				if (nb > INT_MAX)
					printf("Error\n");
			}
		}
		nb = atoint128(argv[1]);
		printf("%lld\n", nb);
	}
	return (0);
}
