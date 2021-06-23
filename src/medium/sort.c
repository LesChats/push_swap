/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:40:13 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/23 18:34:07 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	same_move(t_stack **st, t_tuple move)
{
	static const t_opxx	xx[] = {rr, rrr};
	int					tmp;
	int					key;

	key = (move[0] < 0);
	if (key)
		tmp = max(move[0], move[1]);
	else
		tmp = min(move[0], move[1]);
	move[0] -= tmp;
	move[1] -= tmp;
	tmp = abs(tmp);
	while (tmp--)
		xx[key](st);
}

static void	next_mv(t_stack **st)
{
	t_tuple						move;
	static const t_op			x[] = {rx, rrx};
	static const char *const	s[] = {"ra\n", "rra\n", "rb\n", "rrb\n"};
	int							key;

	move[0] = -st[0]->size;
	move[1] = st[0]->size;
	find_bestm(st, move);
	if (move[0] * move[1] > 0)
		same_move(st, move);
	key = (move[0] < 0);
	if (key)
		move[0] = -move[0];
	while (move[0]--)
		x[key](st[0], s[key]);
	key = (move[1] < 0);
	if (key)
		move[1] = -move[1];
	while (move[1]--)
		x[key](st[1], s[key + 2]);
	px(st, "pa\n");
}

void	medium_sort(t_stack **st, const int *data)
{
	int	align;

	slice(st, data);
	while (st[1]->size)
		next_mv(st);
	align = find_min(st[0]);
	if (align > st[0]->size - align)
	{
		align = st[0]->size - align;
		while (align--)
			rrx(st[0], "rra\n");
	}
	else
		while (align--)
			rx(st[0], "ra\n");
}
