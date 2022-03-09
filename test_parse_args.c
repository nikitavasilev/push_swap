#include <stdio.h>

char	**ft_split(char const *s, char c);

char	**fill_args(int argc, char const *argv[])
{
	size_t	i;
	size_t	j;

	while (argc == 2)
	{
		ft_split(argv[1])
	}
}

int	main(int argc, char const *argv[])
{
	char	**args;

	if (argc > 2)
	{
		args = fill_args(argc, argv);
	}
	return (0);
}
