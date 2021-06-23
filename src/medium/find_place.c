/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:33:02 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/23 18:34:26 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	equal_(t_tuple a, t_tuple b)
{
	a[0] = b[0];
	a[1] = b[1];
}

static int	find_place(const t_stack *st, const int x)
{
	struct s_frame	*frame;
	struct s_frame	*back_frame;
	int				i;

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

void	find_bestm(t_stack **st, t_tuple move)
{
	struct s_frame	*frame;
	struct s_frame	*back_frame;
	t_tuple			tmp;
	int				i;

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
