#include <unistd.h>

int		ft_verify_char(char *str, char c, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_inter(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
	{
		if (ft_verify_char(s1, s1[i], i) == 1)
		{
			j = 0;
			while (s2[j])
			{
				if (s2[j] == s1[i])
				{
					write(1, &s2[j], 1);
					break;
				}
				j++;
			}
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}