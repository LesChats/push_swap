/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:01:19 by abaudot           #+#    #+#             */
/*   Updated: 2021/06/07 17:08:40 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int find_min(const t_stack *st)
{
	struct s_frame	*tmp;
	int				i;
	int				res;
	int				min;

	tmp = st->head;
	min = tmp->item;
	res = 0;
	i = 0;
	while (++i < st->size)
	{
		if ((tmp->next)->item < min)
		{
			min = (tmp->next)->item;
			res = i;
		}
		tmp = tmp->next;
	}
	return (res);
}

int find_max(const t_stack *st)
{
	struct s_frame	*tmp;
	int				i;
	int				res;
	int				max;

	tmp = st->head;
	max = tmp->item;
	res = 0;
	i = 0;
	while (++i < st->size)
	{
		if ((tmp->next)->item > max)
		{
			max = (tmp->next)->item;
			res = i;
		}
		tmp = tmp->next;
	}
	return (res);
}
