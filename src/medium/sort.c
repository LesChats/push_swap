/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:40:13 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/12 17:13:30 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_place(const t_stack *st, const int x)
{
	struct s_frame	*frame;
	struct s_frame	*back_frame;
	int	i;
	
	frame = st->head;
	back_frame = frame;
	i = 0;
	while (i < st->size)
	{
		if (x < frame->item && x > (frame->prev)->item)
			return (i);
		if (x > back_frame->item && x < (back_frame->next)->item)
			return (-i + 1);
		frame = frame->next;
		back_frame = back_frame->prev;
		++i;
	}
	i = find_max(st) + 1;
	if (i == st->size)
		i = 0;
	if (i > st->size - i)
		i = -(st->size - i);
	return (i);
}

static inline void equal_(t_tuple a, t_tuple b)
{
	a[0] = b[0];
	a[1] = b[1];
}

static void	find_bestm(t_stack **st, t_tuple move)
{
	int	i;
	t_tuple	tmp;
	struct s_frame *frame;
	struct s_frame *back_frame;

	frame = st[1]->head;
	back_frame = frame;
	i = -1;
	while (++i < st[1]->size)
	{
		if (count_op(i, 0) >= count_op(move[0], move[1]))
			break ;
		tmp[1] = i;
		tmp[0] = find_place(st[0], frame->item);
		if (count_op(tmp[0], tmp[1]) < count_op(move[0], move[1]))
			equal_(move, tmp);
		tmp[1] = -i;
		tmp[0] = find_place(st[0], back_frame->item);
		if (count_op(tmp[0], tmp[1]) < count_op(move[0], move[1]))
			equal_(move, tmp);
		frame = frame->next;
		back_frame = back_frame->prev;
	}
}

static void same_move(t_stack **st, t_tuple move)
{
	static const t_opxx	xx[] = {rr, rrr};
	int tmp;
	int key;
	

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

void	next_mv(t_stack **st)
{
	t_tuple	move;
	static const t_op	x[] = {rx, rrx};
	static const char *const s[] = {"ra\n", "rra\n", "rb\n", "rrb\n"};
	int key;

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

void medium_sort(t_stack **st, const int *data)
{
	int align;

	//print_stack(st[0]);
	//print_stack(st[1]);
	slice(st, data);
	//print_stack(st[0]);
	//print_stack(st[1]);
	while (st[1]->size)
	{
		next_mv(st);
	//print_stack(st[0]);
	//print_stack(st[1]);
	}
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
