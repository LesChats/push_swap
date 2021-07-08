/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:43:53 by abaudot           #+#    #+#             */
/*   Updated: 2021/07/08 12:00:14 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_b(t_stack **st, int pivot)
{
	const int	size = st[1]->size;
	int			i;

	i = 0;
	while (i < size)
	{
		if (st[1]->head->item == (st[0]->tail->item + 1)
			|| st[1]->head->item == 0)
		{
			px(st, "pa\n");
			rx(st[0], "ra\n");
		}
		else if (pivot <= st[1]->head->item)
			px(st, "pa\n");
		else
			rx(st[1], "rb\n");
		++i;
	}
}

void	split_a(t_stack **st, int pivot)
{
	const int	size = st[0]->size;
	int			i;

	i = 0;
	while (i < size)
	{
		if (pivot >= st[0]->head->item)
			px(st, "pb\n");
		else
			rx(st[0], "ra\n");
		++i;
	}
}

void	half_split(t_stack **st, int pivot, int limit)
{
	int	max_b;
	int	ra;

	ra = 0;
	while (st[0]->head->item <= limit && st[0]->head->item)
	{
		if (st[0]->head->item >= pivot)
		{
			rx(st[0], "ra\n");
			++ra;
		}
		else
			px(st, "pb\n");
	}
	max_b = get_max(st[1]);
	while (ra--)
	{
		if (st[1]->head->item != max_b)
			rrr(st);
		else
			rrx(st[0], "rra\n");
	}
	if (get_min(st[1]) == (st[0]->tail->item + 1))
		stack_quicksort(st);
}

void	check_split(t_stack **st, int limit)
{
	while (st[0]->head->item <= limit && st[0]->head->item)
	{
		if (st[0]->head->item == (st[0]->tail->item + 1))
			rx(st[0], "ra\n");
		else
			px(st, "pb\n");
	}
	if (get_min(st[1]) == (st[0]->tail->item + 1))
		stack_quicksort(st);
}
