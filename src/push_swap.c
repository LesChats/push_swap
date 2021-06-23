/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:26:31 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/23 22:32:38 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	freeAssange(t_stack **st, int *data)
{
	free_stack(st[0]);
	free_stack(st[1]);
	free(data);
}

static inline void	init(int size, char **av, t_stack **st, int *array)
{
	int	rsize;

	rsize = parse(array, av, size);
	if (!rsize)
	{
		write(1, "error\n", 6);
		free(array);
		exit(1);
	}
	if (!(init_stack(st[0], rsize, array)))
	{
		write(1, "error\n", 6);
		free(array);
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
		return (write(1, "\n", 1));
	//data = malloc(sizeof(int) * (ac - 1));
	init(ac - 1, av + 1, ab, data);
	print_stack(ab[0]);
	if (is_sorted(ab[0]))
	{
		write(1, "\n", 1);
		freeAssange(ab, data);
		return (0);
	}
	if (ab[0]->size < 6)
		small_sort(ab);
	else
		medium_sort(ab, data);
	freeAssange(ab, data);
	return (0);
}
