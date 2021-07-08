/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:01:19 by abaudot           #+#    #+#             */
/*   Updated: 2021/07/05 18:28:34 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	find_min(const t_stack *st)
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

int	get_min(const t_stack *st)
{
	struct s_frame	*tmp;
	int				i;
	int				min;

	tmp = st->head->next;
	min = st->head->item;
	i = 0;
	while (++i < st->size)
	{
		if (tmp->item < min)
			min = tmp->item;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max(const t_stack *st)
{
	struct s_frame	*tmp;
	int				i;
	int				max;

	tmp = st->head->next;
	max = st->head->item;
	i = 0;
	while (++i < st->size)
	{
		if (tmp->item > max)
			max = tmp->item;
		tmp = tmp->next;
	}
	return (max);
}

int	find_max(const t_stack *st)
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}
