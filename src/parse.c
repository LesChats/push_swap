/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:34:27 by abaudot           #+#    #+#             */
/*   Updated: 2021/07/08 11:56:43 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static char	ft_atoi(const char *s, long *res)
{
	unsigned int	tmp;

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
		return (*s == 0 && *res > -2147483649);
	}
	while (1)
	{
		tmp = (unsigned)((*s) - '0');
		if (tmp > 9)
			break ;
		*res = *res * 10 + tmp;
		++s;
	}
	return (*s == 0 && *res < 2147483648);
}

static char	ft_atoi_mov(const char *s, long *res, int *i)
{
	unsigned int	tmp;

	*res = 0;
	if (s[*i] == '-')
	{
		while (1)
		{
			tmp = (unsigned)((s[++*i]) - '0');
			if (tmp > 9 || *res > 0)
				break ;
			*res = *res * 10 - tmp;
		}
		return ((s[*i] == 0 || s[*i] == ' ') && *res > -2147483649);
	}
	while (1)
	{
		tmp = (unsigned)((s[*i]) - '0');
		if (tmp > 9 || *res < 0)
			break ;
		*res = *res * 10 + tmp;
		++*i;
	}
	return ((s[*i] == 0 || s[*i] == ' ') && *res < 2147483648);
}

static char	is_in(const int *arr, const int target, const int size)
{
	int	i;

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
	int		i;
	long	num;

	*array = (int *)malloc(sizeof(int) * size);
	if (!*array)
		return (0);
	i = 0;
	while (i < size)
	{
		if (!ft_atoi(av[i], &num))
			return (0);
		if (is_in(*array, num, i))
			return (0);
		(*array)[i] = (int)num;
		++i;
	}
	return (size);
}

int	parse_string(int **array, char *av)
{
	const int	size = ft_strlen(av) * 0.5 + 1;
	long		num;
	int			i;
	int			k;

	*array = (int *)malloc(sizeof(int) * size);
	if (!*array)
		return (0);
	i = 0;
	k = 0;
	while (av[i])
	{
		while (av[i] == ' ')
			++i;
		if (!ft_atoi_mov(av, &num, &i))
			return (0);
		if (is_in(*array, num, k))
			return (0);
		(*array)[k] = (int)num;
		++k;
	}
	return (k);
}
