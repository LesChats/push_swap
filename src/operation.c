/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:26:11 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/12 15:26:13 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
**	considering the data is just an int, it is much faster (en readable)
** to just swap the data rather than the nodes
*/
void swap(t_stack *st)
{
	const int tmp = (st->head)->item;

	(st->head)->item = ((st->head)->next)->item;
	((st->head)->next)->item = tmp;
}

void pop_push(t_stack *dst, t_stack *src)
{
	struct s_frame *tmp;

	tmp = src->head;
	src->head = tmp->next;
	(src->head)->prev = src->tail;
	(src->tail)->next = src->head;
	--src->size;
	if (!dst->size)
	{
		dst->head = tmp;
		(dst->head)->next = tmp;
		(dst->head)->prev = tmp;
		dst->tail = dst->head;
	}
	else
	{
		(dst->head)->prev = tmp;
		tmp->next = dst->head;
		tmp->prev = dst->tail;
		(dst->tail)->next = tmp;
		dst->head = tmp;
	}
	++dst->size;
}

/*
** We use circular linked list so this part is straightforward
** rra
*/
void	tail_to_head(t_stack *st)
{
	st->head = st->tail;
	st->tail = (st->head)->prev;
}

/*
**	ra
*/
void	head_to_tail(t_stack *st)
{
	st->tail = st->head;
	st->head = (st->tail)->next;
}
