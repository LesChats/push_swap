#include <stdlib.h>

static inline int trimspace(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		++i;
	return (i);
}
		
static char ft_atoi(const char *s, int *res, int *i)
{
	unsigned	tmp;

	*res = 0;
	if (s[*i] == '-')
	{
		while (1)
		{
			tmp = (unsigned)((s[++*i]) - '0');
			if (tmp > 9)
				break ;
			*res = *res * 10 - tmp;
		}
		return (s[*i] == 0 || s[*i] == ' ');
	}
	while (1)
	{
		tmp = (unsigned)((s[*i]) - '0');
		if (tmp > 9)
			break ;
		*res = *res * 10 + tmp;
		++*i;
	}
	return (s[*i] == 0 || s[*i] == ' ');
}

static char is_in(const int *arr, const int target, const int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == target)
			return (1);
		++i;
	}
	return (0);
}

int	parse(int *array, char **av, const int size)
{
	int	i;
	int	j;
	int	k;
	int	num;
	
	if (!array)
		return (0);
	k = 0;
	i = 0;
	while (i < size)
	{
		j = trimspace(av[i]);
		while (av[i][j])
		{
			if (!ft_atoi(av[i], &num, &j))
				return (0);
			if (is_in(array, num, k))
					return (0);
			array[k++] = num;
			j += trimspace(av[i] + j);
		}
		++i;
	}
	return (k);
}
