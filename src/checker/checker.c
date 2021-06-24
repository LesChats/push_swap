/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:30:44 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/24 20:22:08 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	freeAssange(t_stack **st, int *data)
{
	free_stack(st[0]);
	free_stack(st[1]);
	free(data);
}

static inline void	init(int size, char **av, t_stack **st, int **array)
{
	int	rsize;

	if (size != 1)
		rsize = parse_multi_arg(array, av, size);
	else
		rsize = parse_string(array, *av);
	if (!rsize)
	{
		write(1, "Error\n", 6);
		free(*array);
		exit(1);
	}	
	if (!(init_stack(st[0], rsize, *array)))
	{
		write(1, "Error\n", 6);
		free(*array);
		exit(1);
	}
	init_stack(st[1], 0, NULL);
}

static char	operation(t_stack **st, const char *s)
{
	char	res;

	if (s[0] == 'p' && (s[1] == 'a' || s[1] == 'b') && s[2] == 0)
		res = spp(st[s[1] - 'a'], st[(s[1] - 'a' + 1) & 1]);
	else if (s[0] == 's' && (s[1] == 'a' || s[1] == 'b') && s[2] == 0)
		res = sswap(st[s[1] - 'a']);
	else if (s[0] == 's' && s[1] == 's' && s[2] == 0)
		res = biswap(st);
	else if (s[0] == 'r' && (s[1] == 'a' || s[1] == 'b') && s[2] == 0)
		res = shtt(st[s[1] - 'a']);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 0)
		res = bihtt(st);
	else if (s[0] == 'r' && s[1] == 'r' && (s[2] == 'a' || s[2] == 'b')
		&& s[3] == 0)
		res = stth(st[s[2] - 'a']);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == 0)
		res = bitth(st);
	else
		return (0);
	return (res);
}

static int	read_(t_stack **st)
{
	t_string	s;

	if (!initilize_string(&s, 4))
		return (0);
	while (getnextline(0, &s) > 0)
	{
		if (!operation(st, s.s))
		{
			free(s.s);
			return (0);
		}
		s.len = 0;
	}
	free(s.s);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		*data;
	t_stack	*ab[2];

	ab[0] = &a;
	ab[1] = &b;
	if (ac < 2)
		return (0);
	init(ac - (1), av + (1), ab, &data);
	if (is_sorted(ab[0]))
	{
		write(1, "OK\n", 3);
		freeAssange(ab, data);
		return (0);
	}
	if (!read_(ab))
		write(1, "Error\n", 6);
	else if (is_sorted(ab[0]) && ab[1]->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	freeAssange(ab, data);
	return (0);
}
