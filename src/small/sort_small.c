/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:56:04 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/09 15:07:00 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	sort_2(t_stack *st)
{
	if ((st->head)->item > (st->head->next)->item)
	{
		printf ("%d > %d\n", st->head->item, st->head->next->item);
		sx(st, "sa\n");
	}
}

static void sort_3(t_stack *st)
{
	const int min = find_min(st);
	if (min == 0)
	{
		sx(st, "sa\n");
		rx(st, "ra\n");
	}
	else if (min == 1)
	{
		if ((st->head)->item > (st->tail)->item)
			rx(st, "ra\n");
		else
			sx(st, "sa\n");
	}
	else
	{
		sort_2(st);
		rrx(st, "rra\n");
	}
}

static void	sort_4(t_stack **st)
{
	const int min = find_min(st[0]);

	if (min == 1)
		sx(st[0], "sa\n");
	else if (min == 2)
	{
		rx(st[0], "ra\n");
		rx(st[0], "ra\n");
	}
	else if (min == 3)
		rrx(st[0], "rra\n");
	if (!is_sorted(st[0]))
		px(st, "pb\n");
	else
		return ;
	sort_3(st[0]);
	px(st, "pa\n");
}

static void	sort_5(t_stack **st)
{
	const int min = find_min(st[0]);

	if (min == 1)
		sx(st[0], "sa\n");
	else if (min == 2)
	{
		rx(st[0], "ra\n");
		rx(st[0], "ra\n");
	}
	else if (min == 3)
	{
		rrx(st[0], "rra\n");
		rrx(st[0], "rra\n");
	}
	else if (min == 4)
		rrx(st[0], "rra\n");
	if (!is_sorted(st[0]))
		px(st, "pb\n");
	else
		return ;
	sort_4(st);
	px(st, "pa\n");
}

void small_sort(t_stack **st)
{
	if (st[0]->size == 2)
		sort_2(st[0]);
	else if (st[0]->size == 3)
		sort_3(st[0]);
	else if (st[0]->size == 4)
		sort_4(st);
	else
		sort_5(st);
}
