#include <stdlib.h>

static char ft_atoi(const char *s, int *res)
{
	unsigned	tmp;

	*res = 0;
	if (*s == '-')
	{
		while (1)
		{
			tmp = (unsigned)((*++s) - '0');
			if (tmp > 9)
				break ;
			*res = *res * 10 - tmp;
		}
		return (*s == 0);
	}
	while (1)
	{
		tmp = (unsigned)((*s) - '0');
		if (tmp > 9)
			break ;
		*res = *res * 10 + tmp;
		++s;
	}
	return (*s == 0);
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

#include <stdio.h>

char parse(int *array, char **av, const int size)
{
	int i;
	int num;

	if (!array)
		return (0);
	i = 0;
	while (i < size)
	{
		if (!ft_atoi(av[i], &num))
		{
			printf("atoi fail %d\n", num);
			return (0);
		}
		if (!is_in(array, num, i))
			array[i] = num;
		else
			return (0);
		++i;
	}
	return (1);
}

	
