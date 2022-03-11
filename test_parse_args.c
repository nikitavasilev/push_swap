#include <stdio.h>

char	**ft_split(char const *s, char c);

char	**fill_args(int argc, char const *argv[])
{
	size_t	i;
	size_t	j;
	char	**digits;

	if (argc == 2)
		digits = ft_split(argv[1], ' ');
	return (digits);
}

int	main(int argc, char const *argv[])
{
	char	**args;
	size_t	i;

	if (argc >= 2)
	{
		args = fill_args(argc, argv);
	}
	i = 0;
	while (args[i])
		printf("%s\n", args[i++]);
	return (0);
}
