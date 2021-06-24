#include <stdlib.h>

static inline int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

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
		
static char ft_atoi_mov(const char *s, int *res, int *i)
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

int	parse_multi_arg(int **array, char **av, const int size)
{
	int i;
	int num;

	*array = (int*)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		if (!ft_atoi(av[i], &num))
			return (0);
		if (is_in(*array, num, i))
			return (0);
		*array[i] = num;
		++i;
	}
	return (size);
}

int	parse_string(int **array, char *av)
{
	const int	size = ft_strlen(av) * 0.5 + 1;
	int			num;
	int			i;
	int			k;

	*array = (int*)malloc(sizeof(int) * size);
	i = 0;
	k = 0;
	while (av[i])
	{
		while (av[i] == ' ')
			++i;
		if (!ft_atoi_mov(av, &num, &i))
			return (0);
		if(is_in(*array, num, k))
			return (0);
		*array[k] = num;
		++k;
	}
	return (k);
}

