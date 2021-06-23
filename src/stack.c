/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:54:01 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/23 17:53:28 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static struct s_frame *new_frame(const int value)
{
	struct s_frame *res;

	res = (struct s_frame *)malloc(sizeof(struct s_frame));
	if (!res)
		return (NULL);
	res->next = NULL;
	res->prev = NULL;
	res->item = value;
	return (res);
}

char	init_stack(t_stack *st, const int size, const int *tab)
{
	struct s_frame	*tmp;

	st->size = 0;
	if (!tab)
		return ('y');
	st->head = new_frame(*tab);
	if (!st->head)
		return (0);
	st->tail = st->head;
	while (++st->size < size)
	{
		tmp = new_frame(tab[st->size]);
		if (!tmp)
			return (free_stack(st));
		tmp->prev = st->tail;
		(st->tail)->next = tmp;
		st->tail = tmp;
	}
	(st->head)->prev = st->tail;
	(st->tail)->next = st->head;
	return ('y');
}

char	free_stack(t_stack *st)
{
	struct s_frame *rmv;
	struct s_frame *next;

	rmv = st->head;
	while (st->size--)
	{
		next = rmv->next;
		free(rmv);
		rmv = next;
	}
	return (0);
}

void	print_stack(t_stack *st)
{
	struct s_frame	*tmp;
	int				i;

	printf("\n|");
	i = 0;
	tmp = st->head;
	while (i < st->size)
	{
		printf("%d ", tmp->item);
		tmp = tmp->next;
		++i;
	}
	printf("|\n");
}

int	is_sorted(t_stack *st)
{
	struct s_frame	*tmp;
	int				i;
	
	if (st->size < 2)
		return (1);
	tmp = st->head;
	i = 0;
	while (++i < st->size)
	{
		if (tmp->item > (tmp->next)->item)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
