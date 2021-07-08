/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:26:31 by abaudot           #+#    #+#             */
/*   Updated: 2021/07/06 14:16:09 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	freeAssange(t_stack **st, int *data)
{
	free_stack(st[0]);
	free_stack(st[1]);
	free(data);
}

static inline void	init(int size, char **av, t_stack **st, int **arr)
{
	int	rsize;

	if (size != 1)
		rsize = parse_multi_arg(arr, av, size);
	else
		rsize = parse_string(arr, *av);
	if (!rsize)
	{
		write(1, "Error\n", 6);
		free(*arr);
		exit(1);
	}
	if (!(init_stack(st[0], rsize, *arr)))
	{
		write(1, "Error\n", 6);
		free(*arr);
		exit(1);
	}
	init_stack(st[1], 0, NULL);
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
	init(ac - 1, av + 1, ab, &data);
	if (is_sorted(ab[0]))
	{
		freeAssange(ab, data);
		return (0);
	}
	if (ab[0]->size < 6)
		small_sort(ab);
	else if (ab[0]->size < TRESHOLD)
		medium_sort(ab, data);
	else
		large_sort(ab, data);
	freeAssange(ab, data);
	return (0);
}
